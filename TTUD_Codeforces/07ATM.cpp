#include<bits/stdc++.h>
using namespace std;

int base[4] = {1, 2, 3, 5};
int W;
int c;
int cnt;
vector<int> money;

void input(){
    cin >> W;
    W = W / 1000;
    cin >> c;

    cnt = 0;
    money.erase(money.begin(), money.end());
    for(int i=0; i<=c; i++){
        int para = pow(10, i);
        money.push_back(para * base[0]);
        money.push_back(para * base[1]);
        money.push_back(para * base[2]);
        money.push_back(para * base[3]);
    }

    sort(money.begin(), money.end(), [] (int a, int b) {
        return a > b;
    });
}

void solve(){
    int r = 0;
    while(W > 0){
        int tmp1 = W / money[r];
        cnt += tmp1;

        W = W % money[r];
        r++;
    }
}

int main(){
    int T;
    cin >> T;

    while(T > 0){
        input();
        solve();

        cout << cnt << " 1\n";
        T--;
    }

    return 0;
}
