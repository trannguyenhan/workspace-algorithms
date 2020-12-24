#include<bits/stdc++.h>
using namespace std;
const int  MAX = 1000;
const int du = 1000000000 + 7;
int n, k1, k2;
int x[MAX];
int cnt = 0;
int so0 = 0, so1 = 0;

void inputData(){
    cin >> n >> k1 >> k2;
}

bool check(int  a, int  i){
    if(a==1) return true;
    else {
        // neu ngay nay nghi -> kiem tra ngay truoc do, neu da nghi thi khong duoc nghi nua
        if(i==0){
            if(x[a-1] == 0) return false;
            else { // x[a-1] == 1
                if(so1<k1) return false;
            }
        } else { // i == 1
            if(x[a-1] == 0){
                if(n-a+1 < k1) return false;
            } else {
                if(so1>=k2) return false;
            }
        }

        return true;
    }
}

void solution(){/*
    int so1 = 0;
    for(int i=n; i>0; i--)
        if(x[i] == 1) so1++;
        else break;
    if(so1!=0 && so1<k1) return; */

    for(int i=1; i<=n; i++)
        cout << x[i];
    cout << endl;
    cnt++;
    //if(cnt == du) cnt = 0;
}

void TRY(int  a){
    for(int  i=0; i<=1; i++){
        if(check(a,i)){
            x[a] = i; // ngay thu a lam viec hoac khong lam viec
            int pre = so1;
            if(i == 1){
                if(x[a-1] == 1) so1++;
                else so1 = 1;
            } else {
                so1 = 0;
            }

            if(a==n) solution();
            else TRY(a+1);

            so1 = pre;
        }
    }
}

int main(){
    inputData();
    TRY(1);
    //cout << cnt % du;
    return 0;
}
