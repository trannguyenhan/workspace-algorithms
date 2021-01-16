#include<bits/stdc++.h>
using namespace std;
const int MAX = 100005;

int n;
int a[MAX];
int S[MAX];
int c_max;

void input(){
    c_max = 0;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
}

void solve(){
    S[0] = 1;
    c_max = S[0];
    for(int i=1; i<n; i++){
        int r;
        for(r=0; r<i; r++){
            if(a[r] + 1 == a[i])
                break;
        }

        if(r >= i){
            S[i] = 1;
            continue;
        }

        int max_k = r;
        for(int j=r+1; j<i; j++){
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
    int T;
    cin >> T;

    while(T > 0){
        input();
        solve();

        cout << c_max << endl;
        T--;
    }
    return 0;
}
