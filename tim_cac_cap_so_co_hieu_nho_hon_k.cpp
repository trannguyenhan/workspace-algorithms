#include <iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;

/*Swap*/
void Swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}
/*Quick_sort*/
int partition(int A[],int left, int right)
{
    int i = left, j = right, pivot = A[left];
    while (i<j)
    {
        while((i <= right) && (A[i] <= pivot)) i++;
        while((j>left) && (A[j]>pivot)) j--;
        if (i<j) Swap(&A[i],&A[j]);
    }
    Swap(&A[j],&A[left]);
    return j;
}
void Quick_sort(int A[], int left, int right)
{
    if (left < right)
    {
        int mid = partition(A,left,right);
        Quick_sort(A,left,mid-1);
        Quick_sort(A,mid+1,right);
    }
    return;
}
/*Ket thuc Quick_sort*/

/*Dem so cap co hieu < k*/
int zzz(int A[], int n, int k)
{
    int dem = 0;
    int i = 0;
    int j = i+1;
    while (i<n)
    {
        if (j<n)
        {
            if (abs(A[i]-A[j])<k)
            {
                dem ++;
                j++;
            } else
            {
                i++;
                j = i+1;
            }
        } else
        {
            i++;
            j = i + 1;
        }
    }
    return dem;
}

int main()
{
    int T;
    int n, k;

    /*T bo test, khi nao T = 0 : khong con bo test nao*/
    cin >> T ;
    while(T>0)
    {
        cin >> n >> k;
        int A[n];
        for (int i=0; i<n; i++)
            cin >> A[i];
        Quick_sort(A,0,n-1);   // Chay thuat toan Quick_sort de sap xep lai day
        cout << zzz(A,n,k) << endl;
        T--;
    }
    return 0;
}
