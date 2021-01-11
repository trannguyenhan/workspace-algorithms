#include<bits/stdc++.h>
using namespace std;
const int MAX = 100005;

int n;
vector< vector<int> > listNode;
int p[MAX];

void input(){
    cin >> n;
    listNode.resize(n+1);
    for(int i=0; i<n-1; i++){
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;

        listNode[tmp1].push_back(tmp2);
        listNode[tmp2].push_back(tmp1);
    }

    for(int i=1; i<=n; i++) p[i] = 0;
}

void solve(){
    queue<int> q;
    q.push(1);
    p[1] = 1;

    while(!q.empty()){
        int x = q.front(); q.pop();

        for(int v : listNode[x]){
            if(p[v] == 0){
                p[v] = x;
                q.push(v);
            }
        }
    }

    for(int i=2; i<=n; i++) cout << p[i] << " ";
}

int main(){
    input();
    solve();

    return 0;
}
