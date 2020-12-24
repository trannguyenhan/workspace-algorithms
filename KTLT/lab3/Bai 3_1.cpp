#include<stdio.h>
#include<iostream>
using namespace std;

int lucas(int n) {

    /****************
        Ho va ten : Nguyen Quang Huy
        MSSV : 20183554
    */
    if(n == 0) return 2;
    if(n == 1) return 1;
    return lucas(n-1) + lucas(n-2);
    /*****************/
}

int main(){
    //printf("Ho Va Ten: Nguyen Quang Huy\n");
    //printf("MSSV: 20183554\n\n");
    cout << lucas(3);
}
