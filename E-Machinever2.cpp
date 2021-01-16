#include<bits/stdc++.h>
using namespace std;

/*
    version DUNG!
    ý tưởng: tại mỗi thời điểm t, ta tính khoảng thời gian lớn nhất bên trái t và lớn nhất bên phải t

*/

const int MAX = 2e6+2;
int N;
int L[MAX], R[MAX]; // L[i]: do dai thoi gian lon nhat ben trai thoi diem i
                    // R[i]: do dai thoi gian lon nhat ben phai thoi diem i
int t_max;
int ans;
int cnt;
void input(){
    cin >> N;
    t_max = 0;
    for(int i = 1; i <= N; i++){
        int s, t;
        cin >> s >> t;
        L[t] = max(L[t], t-s);
        R[s] = max(R[s], t-s);
        if(t > t_max) t_max = t;
    }
}

void solve(){
    // tinh not L[i], R[i]
    for(int i = 1; i <= t_max; i++) L[i] = max(L[i], L[i-1]);
    for(int i = t_max-1; i >= 0; i--) R[i] = max(R[i], R[i+1]);

    ans = -1;
    for(int i = 0; i < t_max; i++){
        int sum = L[i] + R[i+1];
        if(L[i] != 0 && R[i+1] != 0)
            ans = max(ans, sum);
    }

    cout << ans;

}

int main(){
    ios_base::sync_with_stdio(false);
    input();
    solve();
    return 0;
}
