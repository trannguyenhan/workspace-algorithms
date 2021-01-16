#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 100

typedef bool GRAPH[MAX][MAX];


void nhap (int &n, int &m, GRAPH G)
{
    cin >>n>>m;
    int u,v;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            G[i][j] = false;
        }
    }

    for (int i =0; i < m; i++)
    {
        cin>>u>>v;
        G[u][v] = G[v][u] = true;
    }
}


bool kiemTra (int n, int p[MAX], GRAPH G, GRAPH H)
{
    
    for (int i = 0; i < n -1; ++i) {
        for (int j = i+1; j < n ; ++j)
            if (G[i][j] != H[p[i]][p[j]]) return false;
    }

    return true;
}


bool kiemTraDangCau (int n, GRAPH G, GRAPH H){
    int p[n];
    for (int i = 0; i < n; ++i)  p[i] = i;

    do
    {
        if (kiemTra (n, p, G, H )) return true;
    } while (next_permutation(p, p+n));

    return false;
}

int main() {
    int n, m;
    GRAPH G, H;
    nhap(n,m, G);
    nhap(n, m, H);
    if (kiemTraDangCau(n, G, H)) cout<<"YES";
    else cout<<"NO";
    return 0;
}