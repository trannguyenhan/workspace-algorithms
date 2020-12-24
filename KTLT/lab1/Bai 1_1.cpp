# include <stdio.h>
int main(){
    int x, y, z;
    int* ptr;
    printf("Ho Va Ten: Nguyen Quang Huy\n");
    printf("MSSV: 20183554\n\n");
    printf("Enter three integers: ");
    scanf("%d %d %d", &x, &y, &z);
    printf("\nThe three integers are:\n");
    ptr = &x;
    printf("x = %d\n", *ptr);

    /*****************
    Ho va ten : Nguyen Quang Huy
    MSSV : 20183554 */
    ptr = &y;
    printf("y = %d\n", *ptr);
    ptr = &z;
    printf("z = %d", *ptr);
    /*****************/

    return 0;
}
