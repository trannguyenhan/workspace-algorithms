#include<bits/stdc++.h>
using namespace std;

double* maximum(double* a, int size){
    double *max;
    max = a;
    if (a==NULL) return NULL;
    printf("Ho Va Ten: Nguyen Quang Huy\n");
    printf("MSSV: 20183554\n\n");

    /*****************
    Ho va ten : Nguyen Quang Huy
    MSSV : 20183554 */

    for(int i=1; i<size; i++){
        if(a[i] > *max) max = &a[i];
    }
    /*****************/

    return max;
}

int main(){
    double arr[] = {2,4,9,6,7,8};
    cout << *maximum(arr,6);
    return 0;
}
