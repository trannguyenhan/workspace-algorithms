#include<bits/stdc++.h>
using namespace std;
const int MAX = 200;

int n, m;
int a[MAX], b[MAX];
int cnt;

void input(){
    cnt = 0;

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    cin >> m;
    for(int i=0; i<m; i++){
        cin >> b[i];
    }
}

void solve(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(a[i] == b[j]){
                cnt++;
                break;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T;
    cin >> T;
    while(T > 0){
        input();
        solve();

        cout << cnt << endl;

        T--;
    }


    return 0;
}
