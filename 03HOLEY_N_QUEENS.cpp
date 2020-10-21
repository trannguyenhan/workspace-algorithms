#include<bits/stdc++.h>
#define toado pair<int,int>
const int MAX = 50;
using namespace std;
map<toado, bool> holes; // vi tri cac lo
bool visited[MAX][MAX];
int X[MAX]; // X[a] = b, danh dau con hau nam tai hang a va cot b
int n,m;
int cnt = 0;

bool check(int a, int i){
    return true;
}

void solution(){
    for(int i=0; i<n; i++)
        cout << i << " " << X[i] << endl;
    cout << "------" << endl;
    // kiem tra trung cot
    int c[MAX];
    for(int i=0; i<n; i++){
        c[X[i]]++;
    }
    for(int i=0; i<n; i++)
        if(c[X[i]] > 1) return;

    int sub[MAX];
    int dcc[MAX];
    for(int i=0; i<n; i++){
        sub[i] = X[i] - i;
        dcc[sub[i]]++;
    }
    for(int i=0; i<n; i++)
        if(dcc[sub[i]] > 1) return;

    int sum[MAX];
    int dcp[MAX];
    for(int i=0; i<n; i++){
        sum[i] = X[i] + i;
        dcp[sum[i]]++;
    }
    for(int i=0; i<n; i++)
        if(dcp[sum[i]] > 1) return;

    cnt++;
}

void TRY(int a){
    for(int i=0; i<n; i++){ // for tat ca cac cot co the gan cho hang a
        if(check(a,i)){
            X[a] = i; // hang a gan cho cot i <=> con hau nam o hang a va cot i

            if(a == n-1) solution();
            else TRY(a+1);
        }
    }
}

int main(){/*
    n = 1, m = 1;
    while(n!=0 && m!=0){
        cin >> n >> m;
        for(int i=0; i<m; i++){
            int temp1, temp2;
            cin >> temp1, temp2;
            holes[{temp1,temp2}] = true; // bi duc lo
        }

        cnt = 0;
        TRY(1);
        cout << cnt << endl;
    }*/
    cin >> n >> m;/*
    for(int i=0; i<m; i++){
        int temp1, temp2;
        cin >> temp1, temp2;
        holes[{temp1,temp2}] = true; // bi duc lo
    }*/
    TRY(0);
    cout << cnt;
}
