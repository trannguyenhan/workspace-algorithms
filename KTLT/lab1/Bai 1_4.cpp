#include<bits/stdc++.h>
using namespace std;

int counteven(int* arr, int size){
    int count = 0;
    printf("Ho Va Ten: Nguyen Quang Huy\n");
    printf("MSSV: 20183554\n\n");

    /*****************
    Ho va ten : Nguyen Quang Huy
    MSSV : 20183554 */
    for(int i=0; i<size; i++){
        if(arr[i]%2==0) count++;
    }
    /*****************/

    return count;
}

int main(){
    int arr[] = {2,4,5,6,7,8};
    cout << counteven(arr,6);
    return 0;
}
