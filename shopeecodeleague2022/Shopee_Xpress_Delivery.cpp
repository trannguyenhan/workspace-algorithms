#include<bits/stdc++.h>
using namespace std;
const int MAX = 10000;
int M, N;
int x[MAX][MAX];
vector< vector<int> >

void input(){
    cin >> M >> N;
    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            cin >> x[i][j];
        }
    }
}

// point1 (x1, y1), point2 (x2, y2) and 2 point not black hold
// method is distance avg from point1 to point 2
int calcStepFromPointToPoint(int x1, int y1, int x2, int y2){
    int subX = abs(x1 - x2);
    int subY = abs(y1 - y2);

    return subX + subY;
}

void solve(){

}

int main(){
    input();

    return 0;
}
