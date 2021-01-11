#include<bits/stdc++.h>
using namespace std;

int X(int n);
int Y(int n);

int X(int n){
    if(n <= 6) return n;
    return X(n-6) - Y(n-4) + X(n-3) + Y(n-2);
}

int Y(int n){
    if(n <= 6) return 2 * n;
    return Y(n-6) - X(n-5) + Y(n-2) + X(n-1);
}

int sum(int n){
    int x1 = 1, x2 = 2,  x3 = 3, x4 = 4, x5 = 5, x6 = 6;
    int y1 = 2, y2 = 4,  y3 = 6, y4 = 8, y5 = 10, y6 = 12;

    int sum = 1 + 2 + 3 + 4 + 5 + 6 + 2 + 4 + 6 + 8 + 10 + 12;
    int r = 7;
    while(r <= n){
        int x7 = x1 - y3 + x4 + y5;
        int y7 = y1 - x2 + y5 + x6;

        sum += x7 + y7;
        x1 = x2; x2 = x3; x3 = x4; x4 = x5; x5 = x6; x6 = x7;
        y1 = y2; y2 = y3; y3 = y4; y4 = y5; y5 = y6; y6 = y7;

        r++;
    }

    return sum;
}

int main(){
    cout << sum(9);
    return 0;
}
