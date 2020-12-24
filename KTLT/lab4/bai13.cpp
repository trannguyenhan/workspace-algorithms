#include<bits/stdc++.h>
using namespace std;
const int MAX = 1000000;
string str;
int n, cnt;
int slg0[MAX]; // slg0[i] la dem so  luong so 0 trong khoang 0 toi i
int slg1[MAX]; // slg0[i] la dem so  luong so 1 trong khoang 0 toi i

void input(){
    cnt = 0;
    cin >> str;
    n = str.length();

    for(int i=0; i<n; i++){
        if(i==0){
            if(str[i] == '0'){
                slg0[i] = 1;
                slg1[i] = 0;
            } else {
                slg0[i] = 0;
                slg1[i] = 1;
            }
            continue;
        }

        if(str[i] == '0'){
            slg0[i] = slg0[i-1] + 1;
            slg1[i] = slg1[i-1];
        } else {
            slg0[i] = slg0[i-1];
            slg1[i] = slg1[i-1] + 1;
        }
    }
}

void solve(){
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j = j + 2){
            if(i==0){
                if(slg0[j] == slg1[j]) cnt++;
            } else {
                int c0 = slg0[j] - slg0[i-1];
                int c1 = slg1[j] - slg1[i-1];

                if(c0 == c1) cnt++;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    input();
    solve();

    cout << cnt;
    return 0;
}
