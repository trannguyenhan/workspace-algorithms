#include<bits/stdc++.h>
using namespace std;
using Edge = pair<int, int>;
const int MAX = 30;

int n, m;
vector<Edge> vt;
int x[MAX];
int cnt = 0;
bool visited[MAX];

void input(){
    cin >> n >> m;

    for(int i=0; i<m; i++){
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;

        vt.push_back({tmp1, tmp2});
    }

    for(int i=1; i<=n; i++) visited[i] = false;
}

/*datastructure disjoint-set*/
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

void solution(){
    cnt++;
}

bool check(int a, int i){
    if(a > 1){
        if(x[a-1] > i) return false;
        if(i > (m-n+1) + a-1) return false;
    } else if(i > (m-n+1) + 1) return false;

    if(visited[i]) return false;

    for(int j=1; j<=n; j++) makeSet(j);

    for(int j=1; j<a; j++){
        int pfirst = findSet(vt[x[j]].first);
        int psecond = findSet(vt[x[j]].second);
        unionSet(pfirst, psecond);
    }

    int pfirst = findSet(vt[i].first);
    int psecond = findSet(vt[i].second);

    if(pfirst == psecond)  return false;
    return true;
}

void TRY(int a){
    for(int i=0; i<m; i++){
        if(check(a, i)){
            visited[i] = true;
            x[a] = i;

            if(a == n-1) solution();
            else TRY(a+1);

            visited[i] = false;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    input();
    TRY(1);

    cout << cnt;

    return 0;
}
