#include <bits/stdc++.h>
using namespace std;
const int MAX = 800000;

int N;
int frequency[MAX]; // list frequency of each plant
vector<vector<int> > graphs;

void init(){
    // read N
    cin >> N;
    graphs.resize(N);

    // read path
    for(int i=0; i<N-1; i++){
        int first, second;
        cin >> first >> second;

        graphs[first-1].push_back(second-1);
        graphs[second-1].push_back(first-1);
    }

    // read frequency
    for(int i=0; i<N; i++){
        int tmp;
        cin >> tmp;
        frequency[i] = tmp;
    }
}

void destroy(){
    graphs.erase(graphs.begin(), graphs.end());
}

// find all plants between path of plant A and plant B
vector<int> findPlantBetween(int plant_A, int plant_B){
    bool mark[N];
    for(int i=0; i<N; i++) {mark[i] = false;}

    int pre[N];
    vector<int> list; // list of plant need find

    queue<int> q;
    q.push(plant_A);
    mark[plant_A] = true;

    while(!q.empty()){
        int x = q.front(); q.pop();

        for(int v : graphs[x]){
            if(!mark[v]){
                mark[v] = true;
                q.push(v);
                pre[v] = x;
            }
        }
    }

    int x = pre[plant_B];
    while(x != plant_A){
        list.push_back(x);
        x = pre[x];
    }

    return list;
}

int result = 0;

void solve(){
    set<pair<int, int> > edges;

    for(int i=0; i<N; i++){
        // find list plant have frequency equal with plant i
        for(int j=0; j<N; j++){
            if(frequency[i] == frequency[j] && j != i){
                vector<int> listPlants = findPlantBetween(i, j);

                if(listPlants.size() != 0){
                    edges.insert({min(j, listPlants.front()), max(j, listPlants.front())}); // add edge 0
                    edges.insert({min(i, listPlants.back()), max(i, listPlants.back())}); // add edge 0

                    for(int k=1; k<listPlants.size(); k++){
                        edges.insert({min(listPlants[k-1], listPlants[k]), max(listPlants[k-1], listPlants[k])});
                    }
                } else {
                    edges.insert({min(i,j), max(i,j)});
                }

            }
        }
    }

    //for(pair<int,int> el : edges){cout << el.first << " " << el.second << endl;}


    result = N - 1 - edges.size();
}

int main(){
    int T;
    cin >> T;

    int i = 1;
    while(i <= T){
        init();
        solve();
        destroy();

        cout << "Case #" << i << ": " << result << endl;
        i++;
    }


    //ifstream file("chainblock_input.txt");


    return 0;

}
