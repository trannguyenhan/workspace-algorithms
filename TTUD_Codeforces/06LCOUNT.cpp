#include<bits/stdc++.h>
using namespace std;
const int MAX = 100005;

int n;
vector< vector<int> > listNode;
int cnt = 0;
bool visited[MAX];

void input(){
    cin >> n;
    listNode.resize(n+1);

    for(int i=0; i<n-1; i++){
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;

        listNode[tmp1].push_back(tmp2);
        listNode[tmp2].push_back(tmp1);
    }
}

void solve(){
    queue<int> q;
    q.push(1);
    visited[1] = true;

    while(!q.empty()){
        int x = q.front(); q.pop();

        for(int v : listNode[x]){
            if(!visited[v]){
                visited[v] = true;
                q.push(v);
            }
        }
        int size_x = listNode[x].size();
        if(size_x == 1) {
            //cout << "left : " << x << endl;
            cnt++;
        }
    }

    if(listNode[1].size() == 1) cnt--;
}

int main(){
    input();
    solve();

    cout << cnt;
    return 0;
}
