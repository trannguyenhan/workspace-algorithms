#include<bits/stdc++.h>
using namespace std;
const int MAX = 1000005;
int snt[MAX];
int phantich[MAX];

// Sang so nguyen to
void sieve(int N) {
    bool isPrime[N+1];
    for(int i = 0; i <= N;++i) {
        isPrime[i] = true;
    }
    isPrime[0] = false;
    isPrime[1] = false;
    int cnt = 0;
    for(int i = 2; i * i <= N; ++i) {
         if(isPrime[i] == true) {
             // Mark all the multiples of i as composite numbers
             snt[cnt] = i;
             cnt++;
             for(int j = i * i; j <= N; j += i)
                 isPrime[j] = false;
        }
    }
}

// Phan tich N ra thanh tich cac thua so nguyen to
void phanTichSNT(int N){
    int i = 0;
    int cnt = 0;
    while(N > 0){
        if(snt[i] != 0)
            if(N % snt[i] == 0){
                N = N / snt[i];
                phantich[snt[i]]++;
            } else {
                i++;
            }
        else break;
    }
}

int solve(int N){
    phanTichSNT(N);
    phanTichSNT(N+1);
    phanTichSNT(N+2);

    int sum = 1;
    for(int i=0; i<N; i++)
        if(phantich[snt[i]] != 0)
            sum = sum*(phantich[snt[i]]*2-phantich[snt[i]]);
    return sum;
}
int main(){
    int Q;
    cin >> Q;
    sieve(MAX);

    while(Q>0){
        int N;
        cin >> N;
        cout << solve(N) << endl;
        Q--;
    }

    return 0;
}
