#include<bits/stdc++.h>
using namespace std;
const int MAX = 100005;

int n;
int a[MAX];
int total_time;

void input(){
    total_time = 0;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
}

void solve(){
    int r = n-1;
    while(r > 0){
        if(r % 2 == 0){
            for(int i=0; i<r/2; i++){
                a[i] = a[i*2] + a[i*2 + 1];
            }

            a[r/2] = a[r];
            r = r / 2;

            int t_max = 0;
            for(int i=0; i<=r; i++){
                t_max = max(t_max, a[i]);
            }

            total_time += t_max;
        } else {
            for(int i=0; i<=r/2; i++){
                a[i] = a[i*2] + a[i*2 + 1];
            }

            r = r / 2;
            int t_max = 0;
            for(int i=0; i<=r; i++){
                t_max = max(t_max, a[i]);
            }

            total_time += t_max;
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

        cout << total_time << endl;
        T--;
    }


    return 0;
}
