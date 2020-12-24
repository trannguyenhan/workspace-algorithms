#include<bits/stdc++.h>
using namespace std;
const int MAX = 1000005;

int n, m;
vector< vector<int> > vt;
bool visited[MAX];
int cc = 0;

void input(){
    cin >> n >> m;
    vt.resize(n+1);
    for(int i=0; i<m; i++){
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;

        vt[tmp1].push_back(tmp2);
    }

    for(int i=0; i<=n; i++)
        visited[i] = false;
}

void explorer(int u){
    visited[u] = true;
    for(int v : vt[u]){
        if(!visited[v]){
            explorer(v);
        }
    }
}

void dfs(){
    for(int i=1; i<=n; i++){
        if(!visited[i]) {
            cc += 1;
            explorer(i);
        }
    }
}

int main(){
    input();
    dfs();
    cout << cc;
    return 0;
}
