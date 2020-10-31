#include <iostream>

using namespace std;

/*Ham tinh tich cua 2 matran 3x3*/
void TichMatran(int mt1[4][4], int mt2[4][4], int mt[4][4]) // bo di gia tri [0][0]
{
    for (int i=1; i<=3; i++)
        for (int j=1; j<=3; j++)
        {
            mt[i][j] = 0;
            for (int k=1; k<=3; k++)
                mt[i][j] = mt[i][j] + mt1[i][k]*mt2[k][j];
        }
    return;
}
/*Copy 2 matran mt2 = mt1*/
void Copymatran(int mt1[4][4], int mt2[4][4])
{
    for (int i=1; i<=3; i++)
        for (int j=1; j<=3; j++)
            mt2[i][j] = mt1[i][j];
    return;
}
/*Ham tinh mt^n*/
void LuythuaMatran(int mt[4][4], int mtpow[4][4], int n)
{
    int mttemp[4][4];
    Copymatran(mt,mttemp); // mttemp = mt
    for (int i=1; i<n; i++)
    {
        TichMatran(mt,mttemp,mtpow);
        Copymatran(mtpow,mttemp); // sau moi vong gap gan lai mttemp = mtpow
    }
    return; // Luy thua cuoi cung = mtpow
}

/*So Tribonacci thu n*/
int Tribonacci(int n)
{
    if (n ==1 )
        return 1;
    if (n ==2 )
        return 2;
    if (n ==3)
        return 3;
    int mt[4][4];
    // Tao ra ma tran mu n
    mt[1][1] = 1;
    mt[1][2] = 1;
    mt[1][3] = 1;
    mt[2][1] = 1;
    mt[2][2] = 0; // 1 1 1            Fn+2              F3
    mt[2][3] = 0; // 1 0 0 = mt =>    Fn+1 =    mt *    F2  (1)
    mt[3][1] = 0; // 0 1 0            Fn                F1
    mt[3][2] = 1;
    mt[3][3] = 0;

    int mtpow[4][4];
    LuythuaMatran(mt,mtpow,n-1);
    int Tn = mtpow[3][1]*3+mtpow[3][2]*2+mtpow[3][3]*1; // Tu (1) => Tn = ...
    return Tn;
}
/*Tinh Fn*/
int Fn(int n) // Tong cua n so Tribonacci dau tien
{
    if (n ==1)
        return 1;
    if (n ==2)
        return 1+2;
    if (n==3)
        return 1+2+3;
    int SUM = (3*Tribonacci(n)+2*Tribonacci(n-1)+Tribonacci(n-2)+1-3)/2;
    return SUM;
}
int main()
{
    int input; // so test
    cin >> input;

    int arr[input];
    for (int i=0; i<input; i++)
    {
        cin >> arr[i];
    }
    for (int i=0; i<input; i++)
        cout << Fn(arr[i]) << endl;

    //cout << Tribonacci(input);
    return 0;
}
