#include<bits/stdc++.h>
using namespace std;
const long long MAX = 100005;

struct Edge{
    long long ui;
    long long vi;
    long long wi;
};

long long n, m;
vector<Edge> listWi;

void input(){
    cin >> n >> m;
    listWi.resize(m+1);

    for(long long i=0; i<m; i++){
        long long tmp1, tmp2, tmp3;
        cin >> listWi[i].ui >> listWi[i].vi >> listWi[i].wi;
    }
}

/*datastructure disjolong long-set*/
long long r[MAX]; // rank
long long p[MAX]; // parent of node

void makeSet(long long x){
    p[x] = x;
    r[x] = 0;
}

void unionSet(long long x, long long y){

    if(r[x] > r[y]){
        p[y] = x;
    } else {
        p[x] = y;
        if(r[x] == r[y]) r[y] += 1;
    }
}

long long findSet(long long x){
    while(p[x] != x){
        x = p[x];
    }
    return p[x];
}
/*end datastructure*/

bool cmp(Edge a, Edge b){
    return a.wi < b.wi;
}

long long solve(){
    sort(listWi.begin(), listWi.end(), cmp);
    for(long long i=1; i<=n; i++) makeSet(i);
    long long res = 0;

    for(Edge v : listWi){
        long long pu = findSet(v.ui);
        long long pv = findSet(v.vi);
        if(pu != pv){
            //cout << findSet(v.ui) << " " << findSet(v.vi) << " || ";
            //cout << v.ui << " " << v.vi << " , res = ";
            res += v.wi;
            unionSet(pu, pv);
            //cout << res << endl;
            //cout << findSet(v.ui) << " " << findSet(v.vi) << endl;
        }
    }

    return res;
}

int main(){
    input();
    cout << solve();
    return 0;
}
