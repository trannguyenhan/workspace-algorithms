#include<bits/stdc++.h>
using namespace std;
const int MAX = 100005;

int n, m; // n vertex, m edge
vector< vector<int> > vt;
int color[MAX]; // 1 : red, 2 : blue

void input(){
    cin >> n >> m;
    vt.resize(n+1);

    for(int i=0; i<m; i++){
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;

        vt[tmp1].push_back(tmp2);
        vt[tmp2].push_back(tmp1);
    }

    for(int i=1; i<=n; i++) color[i] = 0; // no color
}

bool solve(){
    queue<int> q;
    q.push(1);
    color[1] = 1;

    while(!q.empty()){
        int x = q.front(); q.pop();

        for(int v : vt[x]){
            if(color[v] == 0){
                q.push(v);
                if(color[x] == 1){
                    color[v] = 2;
                } else if(color[x] == 2){
                    color[v] = 1;
                }
            } else {
                if(color[v] == color[x]) return false;
            }
        }
    }

    return true;
}

int main(){
    input();

    if(solve()) cout << "1";
    else cout << "0";
    return 0;
}
