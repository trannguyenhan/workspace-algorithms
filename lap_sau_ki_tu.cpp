#include <iostream>
#include<vector>
#include<string>

using namespace std;

/*Ham doi cho*/
void Swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
    return;
}

/*Ham kiem tra 2 chuoi ki tu co bao nhieu lan lap*/
int KtraSolanlap(string str1, string str2)
{
    int dem = 0;
    int j = 0;
    for (int i=0; i<str1.length(); i++)
    {
        while(str2[j]!=str1[i] && j<str2.length())
        {
            j++;
        }
        if (j<str2.length()) dem++;
        j = 0;
    }
    return dem;
    // Ham nay chua hoan hao lam..... Can chinh sua de nhanh hon nua
    // Nhung voi so lieu it, moi sau < 26 ki tu => tam chap nhan.
}

/*Ham kiem tra xem co bao nhieu lan lap trong bo test*/
int KtraTEST(vector<string> str, int n)
{
    int dem = 0;
    for (int i=0; i<n-1; i++)
    {
        // Kiem tra chuoi hien tai voi chuoi ke tiep
        int temp = KtraSolanlap(str[i],str[i+1]);
        dem = dem + temp;
    }
    return dem;
}

/*Xu li tung hoan vi*/
int XuliHoanVi(int x[], int n, vector<string> str)
{
    int arr[n];
    for (int i=0; i<n; i++)
        arr[i] = x[i+1]-1; // Gan tra lai gia tri arr[0] = 0, arr[1] = 1, arr[2] = 2,...

    vector<string> temp;
    for (int i=0; i<n; i++)
        temp.push_back(str[arr[i]]);

    int dem = 0;
    dem = KtraTEST(temp,n);

    return dem;
}

/*ham in cac hoan vi*/
void InHoanVi(int n, vector<string> str)
{
    int x[n+1];
    int i;
    int k;
    int dem = 0, min = KtraTEST(str,n);
    for (int j=1; j<=n; j++)
        x[j] = j; // Khoi tao x[1] = 1, x[2] = 2, ...
    do
    {
        dem = XuliHoanVi(x,n,str);
        if (dem < min) min = dem;

        i = n-1;
        while(i>0 && x[i] > x[i+1]) i--;
        if (i>0) // Chua gap phai phan tu cuoi day
        {
            k = n; // x[k] la phan tu cuoi day
            while(x[k] < x[i]) k--; // Lui dan k de tim phan tu x[k] dau tien lon hon x[i]
            Swap(x[k],x[i]); // Doi cho x[k] cho x[i]

            int a = i+1, b = n; // Lat nguoc doan cuoi giam dan, a : dau doan, b : cuoi doan
            while(a<b)
            {
                Swap(x[a],x[b]);
                a++;
                b--;
            }
        }
    } while (i>0);
    cout << min << endl;
}
int main()
{

    vector<string> str;
    int n;

    // Nhap du lieu

    cin >> n;
    for (int i=0; i<n; i++)
    {
        string temp;
        cin >> temp;
        str.push_back(temp);
    }



    InHoanVi(n,str);
    //cout << KtraTEST(str,n);
    return 0;
}
