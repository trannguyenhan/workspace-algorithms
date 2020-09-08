#include <iostream>

using namespace std;

void mergeLR(int A[], int first, int mid, int last){
    // Tim phan tu lon nhat trong mang A
    int maxA = A[first];
    for(int i=first+1; i<=last; i++)
        if(A[i] > maxA) maxA = A[i];

    // Khai bao 2 mang L va R
    // Mang trai
    int n1 = mid-first+1;
    int L[n1+1];
    for(int i=first; i<=mid; i++)
        L[i-first] = A[i];
    L[n1] = maxA+1;

    // Mang phai
    int n2 = last-mid-1+1;
    int R[n2+1];
    for(int i=mid+1; i<=last; i++)
        R[i-mid-1] = A[i];
    R[n2] = maxA+1;

    // Bat dau sap xep
    int i=0, j=0;
    for(int k=first; k<=last; k++){
        if(L[i] <= R[j]){
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
    }
    return;
}

void mergeSort(int A[], int first, int last){
    if(first < last){
        int mid = (first + last) / 2;
        mergeSort(A,first,mid);
        mergeSort(A,mid+1,last);
        mergeLR(A,first,mid,last);
    }
}

void printResult(int A[], int n){
    for(int i=0; i<=n; i++)
        cout << A[i] << " ";
    return;
}

int main()
{
    int A[] = {1,6,2,4,3,7,5,8};
    mergeSort(A,0,7);
    printResult(A,7);
    return 0;
}
