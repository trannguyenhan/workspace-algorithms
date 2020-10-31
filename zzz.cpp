#include <iostream>
#include<math.h>
#include<stdlib.h>
using namespace std;

/*Them phan tu x vao trong mang va tra lai vi tri cua x trong mang do*/
int insert_A(int A[], int n, int x)
{
    if (x<A[0])
    {
        for (int i=n; i>0; i--)
            A[i]=A[i-1];
        A[0] = x;
        return 0;
    }
    if (x>A[n-1])
    {
        A[n] = x;
        return n;
    }
    for (int i=0; i<n; i++)
    {
        if (A[i] == x) return i;
        else if ((A[i]<x)&&(A[i+1]>x))
        {
            for (int j=n; j>i+1; j--)
                A[j] = A[j-1];
            A[i+1] = x;
            return i+1;
        }
    }
    // Sau khi ket thuc ham ta da chen duoc x vao mang A sao cho mang A van la day tang dan va
    // tra ve duoc gia tri chi so cua phan tu co gia tri x
}

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

/*In ra k phan tu gan voi x nhat*/
void zzz(int A[], int n, int x, int k)
{
    int chiso = insert_A(A,n,x);
    if (k%2 == 0) // Neu k chan in ra cac phan tu ben canh chiso
    {
        for (int i=chiso+1; i<=chiso+k/2; i++)
            cout << A[i] << " ";
        for (int i=chiso-1; i>=chiso-k/2; i--)
            cout << A[i] << " ";
    } else // Neu k le thi ta in cac phan tu nhu khi k chan roi in them 1 phan tu gan x hon nua
    {
        for (int i=chiso+1; i<=chiso+k/2; i++)
            cout << A[i] << " ";
        for (int i=chiso-1; i>=chiso-k/2; i--)
            cout << A[i] << " ";
        int chiso2 = nearX(A, chiso-k/2-1,chiso+k/2+1,x);
            cout << A[chiso2];

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
        int A[n+1];
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
