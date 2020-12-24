#include <stdio.h>
#include <math.h>

float get_hypotenuse(float x, float y) {
    /****************
        Ho va ten : Nguyen Quang Huy
        MSSV : 20183554
    */

    float z = sqrt(x*x + y*y);
    return z;
    /*****************/
}

int main(){
    printf("Ho Va Ten: Nguyen Quang Huy\n");
    printf("MSSV: 20183554\n\n");
    float x, y;
    scanf("%f%f", &x, &y);

    float z = get_hypotenuse(x, y);
    printf("z = %.2f\n", z);

    return 0;
}
