#include<bits/stdc++.h>
using namespace std;

void dfs(std::vector< std::list<int> > adj) {
    std::stack<int> S;
    std::vector<bool> visited(adj.size());
    S.push(1); // Bắt đầu từ đỉnh số 1
    while (!S.empty()) {
        int u=S.top();
        if (!visited[u]){
            visited[u] = true;
            std::cout<< u << std::endl;
        }
        if (!adj[u].empty()){
            int v=adj[u].front(); adj[u].pop_front();
            if(!visited[v]){
                S.push(v);
            }
        }else { S.pop();}
    }
}

int main(){
    printf("Ho Va Ten: Nguyen Quang Huy\n");
    printf("MSSV: 20183554\n\n");
    int n = 7;
    vector< list<int> > adj;
    adj.resize(n + 1);
    adj[1].push_back(2);
    adj[2].push_back(4);
    adj[1].push_back(3);
    adj[3].push_back(4);
    adj[3].push_back(5);
    adj[5].push_back(2);
    adj[2].push_back(7);
    adj[6].push_back(7);
    dfs(adj);
}
