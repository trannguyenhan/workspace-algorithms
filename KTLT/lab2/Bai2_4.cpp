#include <stdio.h>

int cube(int x) {
    //# trả về lập phương của x
    /****************
        Ho va ten :Nguyen Quang Huy
        MSSV : 20183554
    */
    return x*x*x;
    /*****************/
}

//# viết hàm tính lập phương của một số kiểu double
/*****************/
double cube(double x){
    return x*x*x;
}
/*****************/

int main() {
    printf("Ho Va Ten: Nguyen Quang Huy\n");
    printf("MSSV: 20183554\n\n");
    int n;
    double f;
    scanf("%d %lf", &n, &f);

    printf("Int: %d\n", cube(n));
    printf("Double: %.2lf\n", cube(f));

    return 0;
}
