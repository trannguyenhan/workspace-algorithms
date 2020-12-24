#include <iostream>
using namespace std;

int gcd(int a, int b){
    if (b == 0) return a;
    return gcd(b, a % b);
}

int gcd2(int a, int b){

    //# Khử đệ quy
    /****************
        Ho va ten : Nguyen Quang Huy
        MSSV : 20183554
    */
    while(b != 0){
        int tmp = a % b;
        a = b;
        b = tmp;
    }

    return a;
    /*****************/
}

int main() {
    //printf("Ho Va Ten: Nguyen Quang Huy\n");
    //printf("MSSV: 20183554\n\n");
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b) << endl << gcd2(a, b);
    return 0;
}
