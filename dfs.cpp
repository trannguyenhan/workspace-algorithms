#include <iostream>
#include<string>
#include<vector>
#include<queue>
#include<math.h>

using namespace std;

vector<vector<int> > nhapDSCanh(int V, int E){
    // Do thi (G,E)
    vector<vector<int> > dscanh(V+1);

    for(int i=0; i<E; i++){
        int temp1, temp2;
        cin >> temp1 >> temp2;

        //{temp1,temp2} la 1 canh cua do thi vo huong G
        dscanh[temp1].push_back(temp2);
        dscanh[temp2].push_back(temp1);
    }

    return dscanh;
}

/*Tim kiem theo chieu sau*/
vector<bool> visited;
void explore(int v, vector<vector<int> > &dscanh, int E){
    cout << v << " ";
    visited[v] = true;
    for(int i=0; i<dscanh[v].size(); i++){
        if(!visited[dscanh[v].at(i)]){
            explore(dscanh[v].at(i),dscanh,E);
        }
    }

    /* Ham explore trong tim kiem theo chieu sau DFS :
    explore(G,u):
        visited(u) = true
        for all edge(u,v) la canh
            if visited(v) = false
                explore(G,v)

    */
    return;
}

void dfs(vector<vector<int> > dscanh, int V, int E, int u){
    visited.resize(V+1,false);

    for(int i=1; i<=V; i++){
        int temp = (i-2+u)%V+1;
        if(!visited[temp])
            explore(temp,dscanh,E);
    }
}

int main()
{
    int T;
    cin >> T;

    while(T>0){
        int V, E, u;
        cin >> V >> E >> u;
        vector<vector<int> > dscanh = nhapDSCanh(V,E);
        dfs(dscanh,V,E,u);
        T--;
    }

    return 0;
}
