#include<bits/stdc++.h>
using namespace std;
const int MAX = 21;

int n, m;
int chiphi[MAX][MAX];
bool visited[MAX];
int X[MAX]; // Luu tru duong di
int T[MAX]; // Luu tru chi phi tung buoc di
int costMin = 2147483647;

void inputData(){
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int temp1, temp2, temp3;
        cin >> temp1 >> temp2 >> temp3;
        chiphi[temp1][temp2] = temp3; // chi phi tu thanh pho temp1 toi thanh pho temp2 bang temp3
    }
}

bool check(int a, int i){
    if(chiphi[X[a-1]][i] == 0) return false;
    if(!visited[i]) return true;
    return false;
}

void solution(){
    if(chiphi[X[n]][1] == 0) return;
    int sum = T[n] + chiphi[X[n]][1];
    costMin = min(sum,costMin);
}

void TRY(int a){
    for(int i=2; i<=n; i++){
        if(check(a,i)){
            X[a] = i;
            T[a] = T[a-1] + chiphi[X[a-1]][i];
            visited[i] = true;

            if(a == n) solution();
            else
                if(T[a] < costMin) TRY(a+1); // Su dung nhanh can loai bo 1 so nhanh

            visited[i] = false;
        }
    }
}

int main(){
    inputData();
    visited[1] = true; // Thanh pho 1 la noi xuat phat
    T[1] = 0;
    X[1] = 1;
    TRY(2);
    cout << costMin;
    return 0;
}
