#include<bits/stdc++.h>
using namespace std;
const long long MAX = 100005;
long long N, C;
long long x[MAX];
long long res;

void input(){
    cin >> N >> C;
    for(long long i=0; i<N; i++){
        cin >> x[i];
    }
    sort(x,x+N);
    res = 0;
}

void solve(long long start, long long ends){
    if(start > ends) return;
    long long mid = (start + ends) / 2;

    long long fi = x[0];
    long long cnt = 1;
    for(long long i=1; i<N; i++){
        if(x[i] - fi >= mid){
            fi = x[i];
            cnt++;
        }
    }

    if(cnt < C) solve(start, mid - 1);
    else {
        res = mid;
        solve(mid + 1, ends);
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    long long T;
    cin >> T;
    while(T > 0){
        input();
        solve(0,1000000001);
        cout <<  res << endl;
        T--;
    }

}
