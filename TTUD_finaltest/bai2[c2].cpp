#include<bits/stdc++.h>
using namespace std;
const long long MAX = 100005;

long long n;
long long a[MAX];
long long S[MAX];
long long cnt[MAX];
long long c_max;

void input(){
    c_max = 0;
    cin >> n;
    for(long long i=0; i<n; i++){
        cin >> a[i];
    }

    for(long long i=0; i<n; i++){
        cnt[i] = 0;
        S[i] = -1;
    }

}

void solve(){
    S[0] = 1;
    c_max = S[0];
    for(long long i=1; i<n; i++){
        long long r;
        for(r=0; r<i; r++){
            if(a[r] + 1 == a[i])
                break;
        }

        if(r >= i){
            S[i] = 1;
            continue;
        }

        long long max_k = r;
        for(long long j=r+1; j<i; j++){
            if(a[j] + 1 == a[i]){
                if(S[j] > S[max_k]){
                    max_k = j;
                }
            }
        }

        S[i] = S[max_k] + 1;

        c_max = max(S[i], c_max);
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    long long T;
    cin >> T;

    while(T > 0){
        input();
        solve();

        cout << c_max << endl;
        T--;
    }
    return 0;
}
