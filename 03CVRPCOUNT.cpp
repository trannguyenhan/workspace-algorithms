#include<bits/stdc++.h>
using namespace std;
const int MAX = 25;
int n, K, Q;
int d[MAX];
bool visited[MAX]; // danh dau cac dia diem da di qua
int x[MAX]; // luu lai cac dia diem da di qua
int y[MAX]; // khong mat tinh tong quat, gia su y1<y2<...<yk, them linh canh y0 = 0
int load[MAX]; // tong khoi luong tren xe k
int cnt;

void input(){
    cnt = 0;
    d[0] = 0;
    y[0] = 0;
    cin >> n >> K >> Q;
    for(int i=1; i<=n; i++){
        cin >> d[i];
    }
    for(int i=0; i<=n; i++)
        load[i] = 0;
}

bool check_Y(int a, int i){
    if(visited[i]) return false;
    return true;
}

bool check_X(int a, int b, int i){
    if(i==0) return true;
    if(visited[i]) return false;
    return true;
}

void solution(){
    for(int i=0; i<K; i++)
        if(load[i] > Q) return;
    cnt++;
}

void TRY_X(int b, int a){
    for(int i=0; i<=n; i++){
        if(check_X(a,b,i)){
            x[b] = i;
            visited[i] = true;
            load[a] += d[x[b]];

            if(b == n-K+a-1 || a+1 == K){
                solution();
            } else {
                if(i>0){
                    TRY_X(b+1,a);
                } else {
                    TRY_X(b+1,a+1);
                }

            }

            // recover data structure
            visited[i] = false;
            load[a] -= d[x[b]];
        }
    }
}

void TRY_Y(int a){
    for(int i=y[a-1]+1; i<=n; i++){
        if(check_Y(a,i)){
            y[a] = i; // xe a se di qua diem i
            visited[i] = true;
            load[a] += d[y[a]]; // tai trong cua xe a + them phan di qua dia diem ya

            if(a == K){
                TRY_X(1,1);
            } else {
                TRY_Y(a+1);
            }

            // recover data structure
            visited[i] = false;
            load[a] -= d[y[a]];
        }
    }
}

int main(){
    input();
    TRY_Y(1);
    cout << cnt;
    return 0;
}
