#include<bits/stdc++.h>
using namespace std;

unsigned long long cnk(unsigned long long n, unsigned long long k, unsigned long long m){
    unsigned long long result = 1;
    for(unsigned long long i=n-k+1; i<=n; i++){
        result = result * i;
    }
    for(unsigned long long i=2; i<=k; i++)
        result = result / i;
    return result % m;
}

int main(){
    unsigned long long T;
    cin >> T;
    while(T>0){
        unsigned long long n,k,m;
        cin >> n >> k >> m;
        cout << cnk(n,k,m) << endl;
        T--;
    }
    return 0;
}
