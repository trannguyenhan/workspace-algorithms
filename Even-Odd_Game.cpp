#include<bits/stdc++.h>
using namespace std;
const int MAX = 200005;
int n;
vector<int> a;
vector<int> a_odd;
vector<int> a_even;
int score_Alice;
int score_Bob;
bool turn; // turn = 1 : Alice first, turn = 0 : Bob first
int cnt = 0;

void input(){
    score_Alice = 0, score_Bob = 0;
    if(cnt % 2 == 0) turn = true; // Alice first
    else turn = false;

    cin >> n;
    a.erase(a.begin(), a.end());
    for(int i=0; i<n; i++){
        int tmp;
        cin >> tmp;
        a.push_back(tmp);
    }

    a_odd.erase(a_odd.begin(), a_odd.end());
    a_even.erase(a_even.begin(), a_even.end());
    for(int i=0; i<n; i++){
        if(a[i] % 2 == 0){
            a_even.push_back(a[i]);
        } else {
            a_odd.push_back(a[i]);
        }
    }

    sort(a_odd.begin(), a_odd.end(), [] (int a, int b){
        return a > b;
    });

    sort(a_even.begin(), a_even.end(), [] (int a, int b){
        return a > b;
    });
}

int solve(){
    while(!a_odd.empty() || !a_even.empty()){
        if(turn){
            // Alice first
            if(!a_even.empty()){
                score_Alice += a_even.front(); //cout << "Alice : " << a_even.front() << endl;
                a_even.erase(a_even.begin(), a_even.begin() + 1);
            } else {
                if(!a_odd.empty()){
                    a_odd.erase(a_odd.begin(), a_odd.begin() + 1);
                }
            }

            // Bob next
            if(!a_odd.empty()){
                score_Bob += a_odd.front(); //cout << "Bob : " << a_odd.front() << endl;
                a_odd.erase(a_odd.begin(), a_odd.begin() + 1);
            } else {
                if(!a_even.empty()){
                    a_even.erase(a_even.begin(), a_even.begin() + 1);
                }
            }
        } else {
            // Bob first
            if(!a_odd.empty()){
                score_Bob += a_odd.front(); cout << "Bob : " << a_odd.front() << endl;
                a_odd.erase(a_odd.begin(), a_odd.begin() + 1);
            } else {
                if(!a_even.empty()){
                    a_even.erase(a_even.begin(), a_even.begin() + 1);
                }
            }

            // Alice next
            if(!a_even.empty()){
                score_Alice += a_even.front(); cout << "Alice : " << a_even.front() << endl;
                a_even.erase(a_even.begin(), a_even.begin() + 1);
            } else {
                if(!a_odd.empty()){
                    a_odd.erase(a_odd.begin(), a_odd.begin() + 1);
                }
            }
        }


    }

    if(score_Alice > score_Bob) return 1;
    if(score_Alice == score_Bob) return 0;
    return -1;
}

int main(){
    int T;
    cin >> T;
    while(T > 0){
        input();
        int res = solve();

        if(res == 1) cout << "Alice\n";
        else if(res == -1) cout << "Bob\n";
        else cout << "Tie\n";

        cnt++;
        T--;
    }

    return 0;
}
