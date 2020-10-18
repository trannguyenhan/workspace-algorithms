#include<bits/stdc++.h>
using namespace std;
const unsigned long long  MAX = 1000;
unsigned long long n, k1, k2;
unsigned long long x[MAX];
unsigned long long cnt = 0;
unsigned long long du = 1000000000 + 7;

void inputData(){
    cin >> n >> k1 >> k2;
}

bool check(unsigned long long  a, unsigned long long  i){
    if(a==1) return true;
    else {
        // neu ngay nay nghi -> kiem tra ngay truoc do, neu da nghi thi khong duoc nghi nua
        if(i==0){
            if(x[a-1] == 0) return false;
            else {
                unsigned long long  dem = 0;
                for(unsigned long long  i=a-1; i>=0; i--)
                    if(x[i] == 1) dem++;
                    else break;
                if(dem<k1) return false;
            }
        } else { // i == 1
            if(x[a-1] == 0){
                if(n-a+1 < k1) return false;
            } else {
                unsigned long long  dem = 0;
                for(unsigned long long  i=a-1; i>=0; i--)
                    if(x[i] == 1) dem++;
                    else break;
                if(dem>=k2) return false;
            }
        }

        return true;
    }
}

void solution(){
    cnt++;
    if(cnt==du) cnt=0;
}

void TRY(unsigned long long  a){
    for(unsigned long long  i=0; i<=1; i++){
        if(check(a,i)){
            x[a] = i; // ngay thu a lam viec hoac khong lam viec

            if(a==n) solution();
            else TRY(a+1);
        }
    }
}

int main(){
    inputData();
    TRY(1);
    cout << cnt;
    return 0;
}
