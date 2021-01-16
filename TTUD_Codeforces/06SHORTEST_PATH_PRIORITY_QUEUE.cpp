#include<bits/stdc++.h>
using namespace std;
const long long MAX = 100005;

struct compare{
    bool operator() (pair<long long, long long> a, pair<long long, long long> b){
        return a.second > b.second;
    }
};

long long n, m;
vector< vector<pair<long long, long long> > > vt;
long long s, t;

void input(){
    cin >> n >> m;
    vt.resize(n+1);
    for(long long i=0; i<m; i++){
        long long tmp1, tmp2, tmp3;
        cin >> tmp1 >> tmp2 >> tmp3;

        vt[tmp1].push_back({tmp2, tmp3});
        //vt[tmp2].push_back({tmp1, tmp3});
    }

    cin >> s >> t;
}

long long dijkstra(){
    priority_queue<pair<long long, long long>, vector< pair<long long, long long> >, compare> q;
    long long dist[MAX];

    for(long long i=1; i<=n; i++) dist[i] = 1e9;
    dist[s] = 0; // dist[s] -> s = 0;

    // init queue
    for(long long i=1; i<=n; i++){
        q.push({i, dist[i]});
    }

    // dijkstra
    while(!q.empty()){
        pair<long long, long long> x = q.top(); q.pop();
        long long x_point = x.first;

        for(auto v : vt[x_point]){
            long long v_point = v.first;
            long long v_dist = v.second;

            if(dist[v_point] > dist[x_point] + v_dist){
                dist[v_point] = dist[x_point] + v_dist;
                q.push({v_point, dist[v_point]});
            }
        }
    }

    cout << dist[t];
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    input();
    dijkstra();
    return 0;
}
