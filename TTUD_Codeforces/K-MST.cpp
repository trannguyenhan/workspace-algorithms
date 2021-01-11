#include <bits/stdc++.h>
using namespace std;
const int N = 100;
// data structure for disjoint set
int p[N];
int r[N];
// data structures for graph
int b[N];
int e[N];
int c[N];
int cmin;
int n, m, K;
// data structure for exhaustive search
int x[N];
int f;// trong so cua K-MST
int f_min;// trong so nho nhat cua K-MST
void makeSet(int x){
    p[x] = x; r[x] = 0;
}
int findSet(int x){
    if(x != p[x])
        p[x] = findSet(p[x]);
    return p[x];
}
void link(int x, int y){
    if(r[x] > r[y]){
        p[y] = x;
    }else{
        p[x] = y;
        if(r[y] == r[x]) r[y] = r[y] + 1;
    }
}
void input(){
    cmin = 1e9;
    cin >> n >> m >> K;
    for(int i = 1; i <= m; i++){
        cin >> b[i] >> e[i] >> c[i];
        cmin = min(c[i],cmin);
    }
}
void sortEdge(){
    for(int i = 1; i <= m-1; i++){
        for(int j = i+1; j <= m; j++){
            if(c[i] > c[j]){
                int tmp = b[i]; b[i] = b[j]; b[j] = tmp;
                tmp  = e[i]; e[i] = e[j]; e[j] = tmp;
                tmp = c[i]; c[i] = c[j]; c[j] = tmp;
            }
        }
    }
}
bool checkConnected(){
    for(int v = 1; v <= n; v++) makeSet(v);
    for(int i = 1; i <= K; i++){
        link(findSet(b[x[i]]), findSet(e[x[i]]));
    }
    int r = -1;
    for(int i = 1;i <= K; i++){
        int u = b[x[i]];
        int v = e[x[i]];
        int ru = findSet(u);
        int rv = findSet(v);
        if(ru != rv) return false;
        if(r == -1) r = ru;
        else if(r != ru) return false;
    }
    return true;
}
bool checkCycle(int v, int k){
    // k-1 canh x[1],...x[k-1] KHONG tao chu trinh
    // bo sung them canh thu v (b[v], e[v]) thi co tao chu trinh hay khong
    for(int x = 1; x <= n; x++) makeSet(x);
    // dua k-1 canh da chon vao DS
    for(int i = 1; i <= k-1; i++){
        // dua canh x[i] vao DS
        int r1 = findSet(b[x[i]]);
        int r2 = findSet(e[x[i]]);
        link(r1,r2);
    }
    bool ok = findSet(b[v]) != findSet(e[v]);

    return ok;
}
void solution(){
    //for(int i = 1; i <= K; i++){
    //    cout << "(" << b[x[i]] << "," << e[x[i]] << ")" << endl;
    //}
    //cout << "f = " << f << endl;
    if(checkConnected())
        f_min = min(f_min,f);
    //cout << "-------------" << endl;
}
void Try(int k){// try value for x[k]: chi so cua canh duoc chon vao CK
    for(int v = x[k-1] + 1; v <= m; v++){
        if(checkCycle(v,k)){
            x[k] = v;
            f = f + c[v];
            if(k == K) solution();
            else{
                int g = f;
                for(int j = 1; j <= K-k; j++) g += c[x[k] + j];
                if(g < f_min)
                    Try(k+1);
                else{
                    //cout << "BOUND!!!!!" << endl;
                }
            }
            f = f - c[v];
        }
    }
}
void solve(){
    x[0] = 0;
    f_min = 1e9;
    Try(1);
    cout  << f_min << endl;
}
int main(){
    input();
    sortEdge();
    solve();
}
