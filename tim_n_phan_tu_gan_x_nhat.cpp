#include <iostream>
#include<math.h>
#include<stdlib.h>
using namespace std;

/*Xoa phan tu thu i trong mang A co n phan tu*/
void Del_i(int A[], int i, int &n)
{
    for (int j=i; i<n; i++)
        A[j]=A[j+1];
    n = n - 1;
    return;
}

/*so sanh phan tu nao gan x hon*/
int nearX(int A[], int val1, int val2, int target)
{
    if (target - A[val1] >= A[val2] - target)
        return val2;
    else
        return val1;
}

/*Tim phan tu gan nhat*/
int findzzz(int A[], int n, int target)
{
    if (target<=A[0]) return 0;
    if (target>=A[n-1]) return n-1;

    // tim phan tu gan target nhat
    int i=0, j=n, mid=0;
    while (i<j)
    {
        mid = (i+j)/2;
        if (A[mid] == target)
        {
            Del_i(A,mid,n); // Neu tim duoc phan tu trung voi target thi xoa no khoi mang
        }

        if (target < A[mid])
        {
            if ((mid>0) && (target > A[mid-1]))
                return nearX(A,mid-1,mid,target);
            j = mid; // neu khong tim thay quay tro lai vong lap voi j moi
        } else
        {
            if ((mid<n-1) && (target < A[mid+1]))
                return nearX(A,mid,mid+1,target);
            i = mid + 1;
        }
    }
    return mid;
}

/*In ra k phan tu gan voi x nhat*/
void zzz(int A[], int n, int x, int k)
{
    for (int i=0; i<k; i++)
    {
        int temp = findzzz(A,n,x);
        cout << A[temp] << " ";
        Del_i(A,temp,n);
    }
}
int main()
{
    int T;
    int n,k,X;
    cin >> T;  // Nhap vao so luong bo test
    while (T>0)
    {
        cin >> n >> k >> X; // Nhap vao so luong phan tu n, phan tu k va X
        int A[n];
        for (int i=0; i<n; i++)
        {
            cin >> A[i];
            // Nhap vao mang A cac phan tu theo thu tu tang dan
        }
        zzz(A,n,X,k);
        cout << endl;
        T--;
    }
    return 0;
}
