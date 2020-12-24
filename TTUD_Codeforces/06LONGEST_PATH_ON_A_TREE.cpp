#include<bits/stdc++.h>
using namespace std;
const int MAX = 100006;

int n;
vector< vector<int> > listVer;
map< pair<int, int>, int> wi;
queue<int> q;
bool visited[MAX];
int dist[MAX];

void input(){
    cin >> n;
    listVer.resize(n+1);

    for(int i=1; i<=n-1; i++){
        int tmp1, tmp2, tmp3;
        cin >> tmp1 >> tmp2 >> tmp3;

        listVer[tmp1].push_back(tmp2);
        listVer[tmp2].push_back(tmp1);
        wi.insert({{tmp1,tmp2}, tmp3});
        wi.insert({{tmp2,tmp1}, tmp3});
    }
}

void setDist(){
    for(int i=1; i<=n; i++){
        dist[i] = 0;
        visited[i] = false;
    }
}

pair<int, int> solve(int root){
    q.push(root);
    dist[root] = 0;

    int res = 0;
    int point_farther = 0;

    while(!q.empty()){
        int u = q.front(); q.pop();

        for(int v : listVer[u]){
            if(!visited[v]){
                visited[v] = true;
                q.push(v);
                dist[v] = dist[u] + wi[{u,v}];

                if(dist[v] > res){
                    res = dist[v];
                    point_farther = v;
                }
            }
        }
    }

    return {res, point_farther};
}

int main(){
    input();
    setDist();
    pair<int, int> pa = solve(1);
    int res = pa.first;
    int root = pa.second;

    setDist();
    cout << solve(root).first;
    return 0;
}
