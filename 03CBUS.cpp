#include<bits/stdc++.h>
using namespace std;
const int MAX = 40;

int n, k;
int distanceMin = 2147483647;
int distanceCur = 0;
int passengers = 0; // so hanh khach hien tai tren xe
int dist[MAX][MAX];
bool visited[MAX]; // danh dau
int X[MAX]; // luu tru vi tri duong di
int minDist;

/*input data*/
void inputData(){
    cin >> n >> k;
    for(int i=0; i<=2*n; i++)
        for(int j=0; j<=2*n; j++){
            cin >> dist[i][j];
        }
}

/*Find min dist*/
void findMin(){
    minDist = 2147483647;
    for(int i=0; i<=2*n; i++)
        for(int j=0; j<=2*n; j++){
            if(i!=j)
                minDist = min(minDist,dist[i][j]);
        }
    return;
}

bool check(int a, int i){
    if(passengers == k)
        if(i<=n) return false;
    if(dist[X[a-1]][i] == 0) return false; // Neu khong co duong di toi no -> false
    if(i>n)
        if(!visited[i-n]) return false;
    if(!visited[i]) return true;
    return false;
}

void solution(){
    distanceCur += dist[X[2*n]][0];
    distanceMin = min(distanceMin,distanceCur);
    distanceCur -= dist[X[2*n]][0];
}

void TRY(int a){
    for(int i=1; i<=2*n; i++){
        if(check(a,i)){
            X[a] = i;
            visited[i] = true;
            distanceCur += dist[X[a-1]][i];
            if(i<=n) passengers++;
            else passengers--;

            if(a == 2*n) solution();
            else
                if(distanceCur + (2*n - a)*minDist < distanceMin) TRY(a+1);

            if(i<=n) passengers--;
            else passengers++;
            visited[i] = false;
            distanceCur -= dist[X[a-1]][i];
        }
    }
}

int main(){
    inputData();
    findMin();
    X[0] = 0;
    TRY(1);
    cout << distanceMin;
    return 0;
}
