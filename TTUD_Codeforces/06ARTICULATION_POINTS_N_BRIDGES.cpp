#include<bits/stdc++.h>
using namespace std;
const int MAX = 100005;

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
        vt[tmp2].push_back(tmp1);
    }
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
    cc = 0;
    for(int i=0; i<n; i++){
        cc += 1;
        if(!visited[i]) explorer(i);
    }
}

int main(){
    input();
    dfs();



    return 0;
}
