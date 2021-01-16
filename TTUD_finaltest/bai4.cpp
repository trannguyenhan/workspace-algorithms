#include<bits/stdc++.h>
using namespace std;
using DIEM = pair<int, int>;
const int MAX = 64;

int n, Q;
vector<DIEM> a;
int d[MAX][MAX];
int total_dist = 0;

void input(){
    cin >> n >> Q;

    a.erase(a.begin(), a.end());
    a.resize(n+1);
    a[0] = {0, 0};
    for(int i=1; i<=n; i++){
        int tmp;
        cin >> tmp;
        a[i] = {i, tmp};
    }

    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            cin >> d[i][j];
        }
    }

    sort(a.begin(), a.end(), [](DIEM a, DIEM b){
        return a.second > b.second;
    });

}

void solve(){
    ofstream ofile;
    //ofile.open("output_1.txt");

    int now = 0;
    int r = 0;
    while(Q > 0){
        total_dist += d[now][a[r].first];
        now = a[r].first;

        Q -= a[r].second;
        r++;

        cout << now << " " << a[r-1].second << " " << total_dist <<  endl;
    }

    total_dist += d[r-2][0];

    cout << total_dist << endl;
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
