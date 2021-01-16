#include<bits/stdc++.h>
using namespace std;
const int MAX = 50000;

int n, m;
vector< vector<int> > vt;
bool mark[MAX];

void input(){
    cin >> n >> m;
    vt.resize(n+1);

    for(int i=0; i<m; i++){
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;

        vt[tmp1].push_back(tmp2);
        vt[tmp2].push_back(tmp1);
    }
}

void bfs(int u){
    queue<int> q;
    q.push(u);
    mark[u] = true;

    while(!q.empty()){
        int x = q.front(); q.pop();

        for(int v : vt[x]){
            if(!mark[v]){
                mark[v] = true;
                q.push(v);
            }
        }
    }

    return;
}

int main(){
    input();
    bfs(1);
    return 0;
}
