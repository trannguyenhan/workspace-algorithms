#include<bits/stdc++.h>
using namespace std;
const int MAX = 2004;

int n, m;
vector< vector<int> > listEdge;
int mark[MAX];

void input(){
    cin >> n >> m;

    listEdge.erase(listEdge.begin(), listEdge.end());
    listEdge.resize(n+1);
    for(int i=0; i<m; i++){
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;

        listEdge[tmp1].push_back(tmp2);
        listEdge[tmp2].push_back(tmp1);
    }

    for(int i=0; i<=n; i++) mark[i] = 0;
}

bool solve(){
    queue<int> q;
    q.push(1);
    mark[1] = 1;

    while(!q.empty()){
        int x = q.front(); q.pop();

        for(int v : listEdge[x]){
            if(mark[v] == 0){
                if(mark[x] == 1) mark[v] = 2;
                else mark[v] = 1;
                q.push(v);
            } else {
                if(mark[v] == mark[x]) return false;
            }
        }
    }

    return true;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T;
    cin >> T;

    int cnt = 1;
    while(T > 0){
        input();

        cout << "Scenario #" << cnt << ":" << endl;
        if(solve()) cout << "No suspicious bugs found!";
        else cout << "Suspicious bugs found!";

        cout << endl;

        cnt++;
        T--;
    }

    return 0;
}
