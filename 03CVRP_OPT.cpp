#include<bits/stdc++.h>
using namespace std;
const int MAX = 15;
int n, K, Q;
int d[MAX];
int c[MAX][MAX];
int x[MAX]; // luu tru lai duong di, x[i] = xe i toi giao hang tai diem x[i]

void inputData(){
    cin >> n >> K >> Q;
    for(int i=1; i<=n; i++)
        cin >> d[i];
    for(int i=0; i<=n; i++)
        for(int j=0; j<=n; j++){
            cin >> c[i][j];
        }
}

void TRY(int a){

}

int main(){
    inputData();
    return 0;
}
