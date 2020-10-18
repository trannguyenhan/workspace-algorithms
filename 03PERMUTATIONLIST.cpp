#include<bits/stdc++.h>
using namespace std;
const int MAX = 100000;
int n, k;
int arr[MAX];
int X[MAX]; // Luu tru duong di
bool visited[MAX]; // Mang danh dau duong di
int cnt = 0;

bool check(int a, int i){
    if(a>n) return false;
    if(!visited[i]) return true;
    return false;
}

void solution(){
    cnt++;
    if(cnt == k){
        for(int i=0; i<n; i++)
            cout << X[i] << " ";
    }
}

void TRY(int a){
    for(int i=0; i<n; i++){
        //if(cnt==k) return;
        if(check(a,i)){
            X[a-1] = arr[i];

            visited[i] = true;

            if(a == n){
                solution();
            } else
                if(cnt<=k) TRY(a+1);

            visited[i] = false;
        }
    }
}

int main(){
    cin >> n >> k;
    for(int i=0; i<n; i++)
        arr[i] = i+1; // Cau hinh dau tien

    TRY(1);
    if(cnt < k) cout << "-1";
    return 0;
}
