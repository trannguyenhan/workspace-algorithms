#include<bits/stdc++.h>
using namespace std;
const int MAX = 30;
int H, W, N;
int w[MAX], h[MAX];
int S;

void inputData(){
    cin >> H >> W;
    cin >> N;
    S = 0;
    for(int i=0; i<N; i++){
        cin >> h[i];
        cin >> w[i];
        S += h[i]*w[i];
    }
}

int main(){
    inputData();
    if(S > H*W){
        cout << "0";
    } else cout <<"1";
    return 0;
}
