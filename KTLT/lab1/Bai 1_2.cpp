#include <stdio.h>
int main(){
    printf("Ho Va Ten: Nguyen Quang Huy\n");
    printf("MSSV: 20183554\n\n");
    int a[7]= {13, -355, 235, 47, 67, 943, 1222};
    printf("address of first five elements in memory.\n");
    for (int i=0; i<5;i++)  printf("\ta[%d] ",i);
    printf("\n");

    /*****************
    Ho va ten : Nguyen Quang Huy
    MSSV : 20183554 */
    for (int i=0; i<5;i++)  printf("\t%p ",&a[i]);
    printf("\n");
    /*****************/

    return 0;
}
