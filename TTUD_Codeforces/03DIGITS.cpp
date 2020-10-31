#include<bits/stdc++.h>
using namespace std;
int X[7]; // ={I[0],C[1],T[2],H[3],U[4],S[5],K[6]}
int N;
int cnt = 0;
int visited[10];

bool compute(){
    // ICT - K62 + HUST = N
    int sum = X[0]*100+X[1]*10+X[2] - (X[6]*100 + 62) + X[3]*1000+X[4]*100+X[5]*10+X[2];
    if(sum == N) return true;
    return false;
}

bool check(int a, int i){
    if(!visited[i]) return true;
    return false;
}

void solution(){
    if(compute()) cnt++;
}

void TRY(int a){
    for(int i=1; i<=9; i++){
        if(check(a,i)){
            X[a] = i;
            visited[i] = true;

            if(a == 6) solution();
            else TRY(a+1);

            visited[i] = false;
        }
    }
}

int main(){
    cin >> N;
    TRY(0);
    cout << cnt;
    return 0;
}
