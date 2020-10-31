#include <iostream>
#include<vector>
using namespace std;

/*Tinh gia tri cac so trong day Tribonacci*/
void Tribonacci(int n, vector<int> &vt) // n la so thu tu trong day Tribonacci cua so
{
    int a1 = 1, a2 = 2, a3 = 3; // 3 so dau mac dinh cua day Tribonacci, T[1] = 1, T[2] = 2, T[3] = 3

    vt.push_back(0); // khong lay chi so 0 cua vector vt
    vt.push_back(a1); // vt[1] = T[1], vt[2] = T[2], vt[3] = T[3]
    vt.push_back(a2);
    vt.push_back(a3);

    int i = 4, sum;
    while(i<=n)
    {
        sum = a1 + a2 + a3;
        vt.push_back(sum);  // vt[n+3] = vt[n+2] + vt[n+1] + vt[n]

        a1 = a2;
        a2 = a3;
        a3 = sum;
        i++;
    }
    return;
    // Muc tieu cua ham : gan toan bo cac gia tri trong day so Tribonacci vao vector vt
    // vt[1] = T[1], vt[2] = T[2], vt[3] = T[3], ... vt[n] = T[n]
}

/*Tinh Fn - tong tat ca cac so Tribonacci tu 1 den n*/
int Fn(int n, vector<int> vt)
{
    if (n ==1)
        return 1;
    if (n ==2)
        return 1+2;
    if (n==3)
        return 1+2+3;

    int SUM = (3*vt[n]+2*vt[n-1]+vt[n-2]+1-3)/2;
    // Tinh tong cua day Tribonacci theo cong thuc da duoc thiet lap tu truoc
    // Link anh chung minh cong thuc : http://bit.ly/37UMXab

    return SUM;
}

int main()
{
    int T; // T bo test theo de bai
    cin >> T;

    int Max = 0;
    int arr[T];
    for (int i=0; i<T; i++)
    {
        cin >> arr[i];
        if (arr[i] > Max) Max = arr[i];
        // Tim bo test lon nhat cua de bai
    }

    // Tinh 1 lan duy nhat bo test lon nhat cua de bai
     vector<int> vt;
     Tribonacci(Max,vt);
     // Sau khi tinh sau da co vector vt chua tat ca cac so trong day Tribonacci tu 1 -> max

     for (int i=0; i<T; i++)
     {
         cout << Fn(arr[i],vt) << endl;
     }

    return 0;
}
