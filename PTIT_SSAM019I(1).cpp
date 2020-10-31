#include <iostream>

using namespace std;

/*Ham tinh tung so trong Tribonacci*/
int Tribonacci(int n) // n la so thu tu trong day Tribonacci cua so
{
    int a1 = 1, a2 = 2, a3 = 3; // 3 so dau mac dinh cua day Tribonacci
    if (n ==1 )
        return 1;
    if (n ==2 )
        return 2;
    if (n ==3)
        return 3;
    int i = 4, sum;
    while(i<=n)
    {
        sum = a1 + a2 + a3;
        a1 = a2;
        a2 = a3;
        a3 = sum;
        i++;
    }
    return sum;
}

/*Tinh Fn*/
int Fn(int n) // Tong cua n so Tribonacci dau tien
{
    if (n ==1)
        return Tribonacci(1);
    if (n ==2)
        return Tribonacci(1)+Tribonacci(2);
    if (n==3)
        return Tribonacci(1)+Tribonacci(2)+Tribonacci(3);
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
    return 0;
}
