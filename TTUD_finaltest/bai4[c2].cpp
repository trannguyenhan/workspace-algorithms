#include<bits/stdc++.h>
using namespace std;
const int MAX = 64;

int n, Q;
int a[MAX];
int d[MAX][MAX];
int total_dist = 0;
int min_total_dist = 0;
int total_weight = 0;
int x[MAX];
bool visited[MAX];

void input(){
    cin >> n >> Q;

    a[0] = 0;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }

    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            cin >> d[i][j];
        }
    }
}

bool check(int a, int i){
    if(visited[i]) return false;
}

void solution(int a){
    total_dist += d[x[a]][0];
    min_total_dist = min(min_total_dist, total_dist);

    total_dist -= d[x[a]][0];
}

void TRY(int k){
    for(int i=1; i<=n; i++){
        if(check(k ,i)){
            x[k] = i;
            visited[i] = true;
            total_weight += a[i];
            total_dist += d[x[k-1]][x[k]];

            if(total_weight > Q) solution(k);
            else TRY(k+1);

            visited[i] = false;
            total_weight -= a[i];
            total_dist -= d[x[k-1]][x[k]];
        }
    }
}

void solve(){
    ofstream ofile;
    ofile.open("output_1.txt");

    x[0] = 0;
    TRY(1);

    cout << min_total_dist << endl;


    /*
    ofile << total_dist << endl;
    ofile << r << endl;
    for(int i=0; i<=r-1; i++)
        ofile << a[i].first << " ";
    */
    ofile.close();
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    input();
    solve();

    return 0;
}
