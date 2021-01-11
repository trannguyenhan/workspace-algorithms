#include<bits/stdc++.h>
using namespace std;
const int MAX = 40;

struct node {
    int ui;
    int vi;
    int wi;

    node(int ui, int vi, int wi){
        this->ui = ui;
        this->vi = vi;
        this->wi = wi;
    }
};

int n, m, k;
int min_weight;
int total_weigh;
int cmin;
int x[MAX];
bool visited[MAX];
vector<node> listEdge;

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

void input(){
    cin >> n >> m >> k;
    min_weight = INT_MAX;
    total_weigh = 0;
    cmin = INT_MAX;
    for(int i=0; i<m; i++){
        int tmp1, tmp2, tmp3;
        cin >> tmp1 >> tmp2 >> tmp3;

        listEdge.push_back(node(tmp1, tmp2, tmp3));
        cmin = min(cmin, tmp3);
    }
}

bool check(int a, int i){
    if(visited[i]) return false;

    for(int j=1; j<=n; j++) makeSet(j);
    for(int j=1; j<a; j++){
        int pa = findSet(listEdge[x[j]].ui);
        int pb = findSet(listEdge[x[j]].vi);

        unionSet(pa, pb);
    }

    int pa = findSet(listEdge[i].ui);
    int pb = findSet(listEdge[i].vi);

    if(pa == pb) return false;
    return true;
}

void solution(){
    min_weight = min(min_weight, total_weigh);
}

void TRY(int a){
    for(int i=0; i<m; i++){
        if(check(a, i)){
            visited[i] = true;
            x[a] = i;
            total_weigh += listEdge[x[a]].wi;

            if(a == k) solution();
            else if(total_weigh + (k-a)*cmin < min_weight) TRY(a+1);

            visited[i] = false;
            total_weigh -= listEdge[x[a]].wi;
        }
    }
}

int main(){
    input();
    TRY(1);

    if(min_weight == INT_MAX) cout << "-1";
    else cout << min_weight;
    return 0;
}
