#include<bits/stdc++.h>
using namespace std;
const int MAX = 100005;
int n;
int p[MAX];
string s;
queue<int> hanh_lang;
stack<int> chuong;

void input(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> p[i];
    }

    for(int i=n-1; i>=0; i--)
        chuong.push(p[i]);

    cin >> s;
}

void solve(){
    int lens = s.length();
    for(int i=0; i<lens; i++){
        if(s[i] == 'C'){
            if(!chuong.empty()){
                int tmp_C = chuong.top(); chuong.pop();
                hanh_lang.push(tmp_C);
            }
        } else {
            if(!hanh_lang.empty()){
                int tmp_H = hanh_lang.front(); hanh_lang.pop();
                chuong.push(tmp_H);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    input();
    solve();
    for(int i=0; i<n; i++){
        cout << chuong.top() << " ";
        chuong.pop();
    }

    return 0;
}
