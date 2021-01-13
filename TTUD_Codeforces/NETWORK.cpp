#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 1;
const int K = 2e3+1;
struct Edge{
    int nod, w;
    Edge(int _nod, int _w){
        nod = _nod; w = _w;
    }
};
vector<Edge> A[N];
int n,k;
int p[N];// p[v] is the parent of v
int d[N];// d[v] is the degree of v
int wp[N];// wp[v] is the weight of edge (v,p[v])
int r; // root
int S[N];
int S1[N];// S1[u] la trong so k-path nho nhat di tu 1 con chau x cua u,
                  // den u, roi di xuong 1 con chau y nao do khac

int R[N][K];
void input(){
    cin >> n >> k;
    int m;
    cin >> m;
    for(int i = 1; i <= m; i++){
        int u,v,w;
        cin >> u >> v >> w;
        A[u].push_back(Edge(v,w));
        A[v].push_back(Edge(u,w));
    }
}
void print(){
    for(int v = 1; v <= n; v++){
        cout << "A[" << v << "] = ";
        for(int i = 0; i < A[v].size(); i++){
            cout << "(" << A[v][i].nod << "," << A[v][i].w << ") ";
        }
        cout << endl;
    }
}
void dfs(int u){
    for(int i = 0; i < A[u].size(); i++){
        int v = A[u][i].nod;
        if(p[v] == -1){
            p[v] = u;
            wp[v] = A[u][i].w;
            dfs(v);
        }
    }
}
void solve(){
    r = 1;
    for(int v = 1; v <= n; v++) p[v] = -1;
    p[r] = r;
    dfs(r);

    // compute R[v,h]
    int INF = 1e9;
    for(int  v = 1; v <= n; v++){
        R[v][0] = 0;
        for(int h = 1; h <= k; h++)
            R[v][h] = INF;
    }

    queue<int> Q;
    for(int v = 1; v <= n; v++){
         d[v] = A[v].size();
         if(v != r && d[v] == 1) Q.push(v);
    }


    while(!Q.empty()){
        int v = Q.front(); Q.pop();
        for(int h = 0; h <= k-1; h++)if(R[v][h] < INF){
            if(R[p[v]][h+1] >= INF){
                R[p[v]][h+1] = wp[v] + R[v][h];

            }else{
                if(R[p[v]][h+1] > wp[v] + R[v][h]){
                    R[p[v]][h+1] = wp[v] + R[v][h];

                }
            }
        }
        d[p[v]]--;
        if(d[p[v]] == 1 && p[v] != r)
            Q.push(p[v]);
    }


    // compute S1
    for(int u = 1; u <= n; u++){
        S1[u] = INF;
        for(int q = 0; q <= k-2; q++){
            for(int i = 0; i < A[u].size(); i++){
                for(int j = i+1; j < A[u].size(); j++){
                    if(A[u][i].nod != p[u] && A[u][j].nod != p[u]){
                        int wi = A[u][i].w;
                        int vi = A[u][i].nod;
                        int wj = A[u][j].w;
                        int vj = A[u][j].nod;
                        if(S1[u] >= INF){
                            S1[u] = R[vi][q] + wi + R[vj][k-q-2] + wj;
                        }else{
                            S1[u] = min(S1[u],R[vi][q] + wi + R[vj][k-q-2] + wj);
                        }
                    }
                }
            }
        }
    }

    // compute S in a bottom-up fashion
    for(int u = 1; u <= n; u++){
        d[u] = A[u].size();
        if(d[u] == 1 && u != r)
            Q.push(u);

        S[u] = min(R[u][k],S1[u]);
    }

    while(!Q.empty()){
        int u = Q.front(); Q.pop();
        if(S[p[u]] >= INF)
            S[p[u]] = S[u];
        else
            S[p[u]] = min(S[p[u]],S[u]);
        d[p[u]]--;

        if(d[p[u]] == 1 && p[u] != r)
            Q.push(p[u]);
    }
     cout << S[r] << endl;
}
int main(){
    freopen("NETWORKS11.INP","r",stdin);
    input();
    //print();
    solve();
}
