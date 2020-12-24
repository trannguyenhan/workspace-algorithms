#include<bits/stdc++.h>
using namespace std;
struct data {
    int ai;
    int ki;

    data(int ai, int ki){
        this->ai = ai;
        this->ki = ki;
    }
};

struct compare{
    bool operator() (data a, data b){
        int ra, rb;

        if(a.ai <= a.ki) ra = a.ai;
        else ra = a.ki;

        if(b.ai <= b.ki) rb = b.ai;
        else rb = b.ki;

        return ra < rb;
    }
};

int n, s, kill_enemy, total_enemy;
priority_queue<data, vector<data>, compare> p_q;

void input(){
    cin >> n >> s;
    kill_enemy = 0;
    total_enemy = 0;
    for(int i=0; i<n; i++){
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        total_enemy += tmp1;
        p_q.push(data(tmp1, tmp2));
    }
}

void solve(){
    while(!p_q.empty() && s>0){
        data inf = p_q.top(); p_q.pop();

        if(inf.ai <= inf.ki){
            kill_enemy += inf.ai;
        } else {
            int nenemy = inf.ai - inf.ki;
            p_q.push(data(nenemy, inf.ki));
            kill_enemy += inf.ki;
        }

        s -= 1;
    }
}

int calc_enemy(){
    /*
    int sum = 0;
    while(!p_q.empty()){
        data v = p_q.top(); p_q.pop();

        sum += v.ai;
    }
    return sum;
    */
    return total_enemy - kill_enemy;
}

int main(){
    input();
    solve();
    cout << calc_enemy();

    /*
    while(!p_q.empty()){
        auto v = p_q.top(); p_q.pop();

        cout << v.ai << " " << v.ki << endl;
    }
    */
    return 0;
}
