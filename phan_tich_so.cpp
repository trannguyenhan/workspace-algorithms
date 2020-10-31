#include <iostream>
#include<vector>
using namespace std;

int N;
// Ta co mang x luu nghiem
// Mang t luu tru tong, co :  x[1] + ... + x[i] = t[i]
// ca 2 mang x, t deu khong xet toi gia tri dau, x[0] = 1, t[0] = 0;
int t[31];
int x[31];

// Do ket qua in ra moi lan la khac nhau vi the can them 1 tham so truyen vao la so phan tu
void inketqua(int k)
{
    cout << "(";
    for (int i=1; i<k; i++)
        cout << x[i] << " ";
    cout << x[k]<< ") ";
    return;
}

//Quay quay
void Try(int i)
{
    int j;
    // x[i] <= N-t[i-1], len xet x[i] tu x[i-1] toi N-t[i-1]
    for (j = x[i-1]; j<=(N-t[i-1])/2; j++)
    {
        x[i] = j;
        t[i] = t[i-1] + x[i];
        Try(i+1);
    }

    // Khi vong for ben tren khong chay tuc la ta da duoc j > N-t[i-1] => da het j can xet
    // Luc nay phan tu cuoi cung x[i] chua duoc gan => x[i] = N-t[i-1] (phan con lai)
    // Hay neu x[i] la phan tu cuoi thi bat buoc no phai bang N-t[i-1]
    x[i] = N-t[i-1];
    inketqua(i);
    return;
}
int main()
{
    cin >> N;
    x[0] = 1;
    t[0] = 0;

    Try(1);
    return 0;
}
