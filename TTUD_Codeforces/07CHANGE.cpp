#include<bits/stdc++.h>
using namespace std;

int n;
int x[6] = {500, 100, 50, 10, 5 ,1};
int cnt = 0;

void input(){
    cin >> n;
    n = 1000 - n;
}

void solve(){
    int r = 0;
    while(n > 0){
        int t = n / x[r];
        int d = n % x[r];

        cnt += t;
        n = d;
        r++;
    }
}

int main(){
    input();
    solve();

    cout << cnt;

    return 0;
}
