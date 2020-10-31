#include <iostream>
using namespace std;

const int P = 1000000000 + 7;
//const unsigned long long P = 7;

// if n > P, reValue(n), so that : n congruent reValue(n) mod P
int reValue(unsigned long long n){
    if(n<P) return n;
    unsigned long long buffer = n / P;
    int result = n - buffer*P;
    return result;
}

// a^P congruent a mod P => b = P.n + x => a^b congruent a^(n+x) mod P
// func return n + x
unsigned long long reValueEXP(unsigned long long b){
    unsigned long long n = b / P;
    unsigned long long x = b - n * P;
    return n + x;
}

// find congruent mul(a,b) mod P, so that : it < P
unsigned long long mul(int a, int b){
    unsigned long long S = a * b;
    S = reValue(S);

    return S;
}

// exp(a,b) with small number
unsigned long long expmodSmall(unsigned long long a, unsigned long long b){
    unsigned long long S = 1;
    for(unsigned long long i=0; i<b; i++){
        S = S * a;
        S = reValue(S);
    }
    return S;
}

unsigned long long expmod(unsigned long long a, unsigned long long b){
    if(b%2 == 0){
        unsigned long long temp = expmodSmall(a,b/2);
        temp = temp * temp;
        temp = reValue(temp);
        return temp;
    } else {
        unsigned long long temp = expmodSmall(a,b/2);
        temp = temp * temp;
        temp = reValue(temp);
        temp = temp * a;
        temp = reValue(temp);
        return temp;
    }
}

int main() {
    unsigned long long a,b;
    cin >> a >> b;

    a = reValue(a); // a^b congruent reValue(a)^b mod P
    b = reValueEXP(b);
    b = reValueEXP(b);

    cout << expmod(a,b);
    return 0;
}
