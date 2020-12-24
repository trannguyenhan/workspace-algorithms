#include<bits/stdc++.h>
using namespace std;

void reversearray(int arr[], int size){
    int l = 0, r = size - 1, tmp;

    /*****************
    Ho va ten : Nguyen Quang Huy
    MSSV : 20183554 */
    while(l<r){
        tmp = arr[l];
        arr[l] = arr[r];
        arr[r] = tmp;
        l++;
        r--;
    }
    /*****************/
}

void ptr_reversearray(int *arr, int size){
    int l = 0, r = size - 1, tmp;

    /*****************
    Ho va ten : Nguyen Quang Huy
    MSSV : 20183554 */
    while(l<r){
        tmp = arr[l];
        arr[l] = arr[r];
        arr[r] = tmp;
        l++;
        r--;
    }
    /*****************/
}

int main(){
    printf("Ho Va Ten: Nguyen Quang Huy\n");
    printf("MSSV: 20183554\n\n");
    int arr[] = {2,4,9,6,7,8};
    ptr_reversearray(arr,6);
    for(int i=0; i<6; i++)
        cout << arr[i] << " ";
}












