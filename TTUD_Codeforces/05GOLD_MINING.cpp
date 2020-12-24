#include<bits/stdc++.h>
using namespace std;
const int MAX = 100000;
int n, L1, L2;
int a[MAX];
int s[MAX];
int res;

void input(){
    cin >> n >> L1 >> L2;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
}

void solve(){
    s[0] = a[0];
    res = s[0];
    for(int i=1; i<n; i++){
        int max_j = 0;
        for(int j=i-L2; j<=i-L1; j++){
            if(j >= 0){
                max_j = max(max_j, s[j]);
            }
        }
        s[i] = max_j + a[i];
        res = max(res, s[i]);
    }
}

int main(){
    input();
    solve();
    cout << res;
}
