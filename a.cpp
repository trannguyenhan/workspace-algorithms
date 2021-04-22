#include<bits/stdc++.h>
using namespace std;
const int MAX = 100000;

int n;
int x[MAX], y[MAX];
int p[MAX];
bool mark[MAX];
int min_tichvohuong;
int tichvohuong;

void input(){
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> x[i];
    }

    for(int i=0; i<n; i++){
        cin >> y[i];
    }

    for(int i=0; i<n; i++){
        mark[i] = false;
    }

    min_tichvohuong = INT_MAX;
    tichvohuong = 0;
}

int tich_vo_huong(int a[MAX], int b[MAX], int n){
    int tichvohuong = 0;
    for(int i=0; i<n; i++){
        tichvohuong += a[i]*b[i];
    }

    return tichvohuong;
}

bool check(int a, int i){
    if(mark[i]){
        return false;
    }

    return true;
}

void solution(){
    if(tichvohuong < min_tichvohuong){
        min_tichvohuong = tichvohuong;
    }
}

int TRY(int a){
    for(int i=0; i<n; i++){
        if(check(a, i)){
            mark[i] = true;
            p[a] = y[i];
            tichvohuong += x[a] * p[a];

            if(a == n-1){
                solution();
            } else {
                TRY(a + 1);
            }

            mark[i] = false;
            tichvohuong -= x[a] * p[a];
        }
    }
}

void solve(){
    input();
    TRY(0);
}

int main(){
    int T;
    cin >> T;
    int cnt = 1;
    while(T>0){
        solve();
        cout << "Case #" << cnt << ": " << min_tichvohuong << endl;
        cnt++;
        T--;
    }
}
