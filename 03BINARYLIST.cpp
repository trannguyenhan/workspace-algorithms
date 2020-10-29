#include<bits/stdc++.h>
using namespace std;
const int MAX = 100000;
int n, k ,ii;
int cnt = 0;
int cnt1 = 0;
int X[MAX];

bool check(int a, int i){
    if(cnt >= k) return false;
    int r = 0;
    if(i == 0){
        for(int j=a-1; j>0; j--){
            if(X[j] == 0) r++;
            else break;
        }
        if(r >= ii-1) return false;
    }
    cnt1 = 0;
    return true;
}

void solution(){
    cnt++;
    if(cnt == k)
        for(int i=1; i<=n; i++)
            cout << X[i] << " ";
}

void TRY(int a){
    for(int i=0; i<=1; i++){
        if(check(a,i)){
            X[a] = i;

            if(a == n) solution();
            else TRY(a+1);
        }
    }
}

int main(){
    cin >> n >> k >> ii;
    TRY(1);
    if(cnt != k) cout << "-1";
    return 0;
}
