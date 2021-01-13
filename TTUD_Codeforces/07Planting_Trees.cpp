#include<bits/stdc++.h>
using namespace std;
const int MAX = 1000004;

struct planting{
    int start;
    int en;
};

int n;
int t[MAX];
planting t_time[MAX];

void input(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> t[i];
    }

    sort(t, t+n, [] (int a, int b) {
        return a > b;
    });
}

void solve(){
    int time = 0;
    for(int i=0; i<n; i++){
        t_time[i].start = time;
        t_time[i].en = time + t[i] + 1;
        time += 1;
    }

    int max_time = 0;
    for(int i=0; i<n; i++){
        max_time = max(max_time, t_time[i].en);
    }

    cout << max_time + 1;
}

int main(){
    input();
    solve();
    return 0;
}
