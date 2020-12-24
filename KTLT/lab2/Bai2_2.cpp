#include <stdio.h>
#include<bits/stdc++.h>
using namespace std;

void rotate(int &x, int &y, int &z) {
    /****************
        Ho va ten : Nguyen Quang Huy
        MSSV : 20183554
    */

    int tmp = x;
    x = y;
    y = z;
    z = tmp;
    /*****************/
}

int main() {
    printf("Ho Va Ten: Nguyen Quang Huy\n");
    printf("MSSV: 20183554\n\n");
    int x, y, z;

    //# Nhập 3 số nguyên
    /*****************/
    cin >> x >> y >> z;
    /*****************/

    printf("Before: %d, %d, %d\n", x, y, z);
    rotate(x, y, z);
    printf("After: %d, %d, %d\n", x, y, z);

    return 0;
}
