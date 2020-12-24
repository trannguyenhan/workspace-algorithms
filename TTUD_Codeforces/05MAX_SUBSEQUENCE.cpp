#include<bits/stdc++.h>
using namespace std;
const int MAX = 1000005;

int n;
int a[MAX];
int S[MAX];
int res;

void input(){
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> a[i];
}

void solve(){
    S[0] = a[0];
    res = S[0];

    for(int i=1; i<n; i++){
        if(S[i-1] > 0){
            S[i] = S[i-1] + a[i];
        } else {
            S[i] = max(S[i-1], a[i]);
        }

        res = max(res, S[i]);
    }
}

int main(){
    input();
    solve();

    cout << res;
    return 0;
}
