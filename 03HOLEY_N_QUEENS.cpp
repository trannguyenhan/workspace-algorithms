#include<bits/stdc++.h>
#define toado pair<int,int>
const int MAX = 50;
using namespace std;
map<toado, bool> holes; // vi tri cac lo
bool visited[MAX][MAX];
toado X[MAX];
int n,m;
int cnt = 0;

void danhDau(int i, int j){
    for(int k=0; k<n; k++){
        visited[k][j] = true;
        visited[i][k] = true;
    }
}

void luuTrangThai(bool pre[MAX][MAX], bool visited[MAX][MAX]){
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            pre[i][j] = visited[i][j];
}

bool check(int a, int i, int j){
    return true;
}

void solution(){
    cnt++;
}

void TRY(int a){
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++){
            if(check(a,i,j)){
                X[a] = {i,j};
                bool pre[MAX][MAX]; // trang thai truoc khi danh dau
                luuTrangThai(pre,visited);
                danhDau(i,j);

                if(a == n) solution();
                else TRY(a+1);

                luuTrangThai(visited,pre);

            }
        }
}

int main(){
    n = 1, m = 1; /*
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
