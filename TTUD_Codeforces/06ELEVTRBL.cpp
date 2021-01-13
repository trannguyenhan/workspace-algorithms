#include<bits/stdc++.h>
using namespace std;
const int MAX = 1000004;

int f, s, g, u, d;
vector< vector<int> > vt;
int dist[MAX];

void input(){
    cin >> f >> s >> g >> u >> d;

    vt.resize(f+1);
    for(int i=1; i<=f; i++){
        int up = i + u;
        int down = i - d;

        if(up <= f) vt[i].push_back(up);
        if(down > 0) vt[i].push_back(down);
    }

    for(int i=0; i<=f; i++) dist[i] = -1;
}

void solve(){
    queue<int> q;
    q.push(s);
    dist[s] = 0;

    while(!q.empty()){
        int x = q.front(); q.pop();

        for(int v : vt[x]){
            if(dist[v] = -1){
                dist[v] = dist[x] + 1;
                q.push(v);
            }

            if(v == g) return;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    input();
    solve();

    if(dist[g] == -1) cout << "use the stairs";
    else cout << dist[g];
    return 0;
}
