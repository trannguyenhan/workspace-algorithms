#include <iostream>
#include<vector>
#include<string>
using namespace std;

/*Ham doi cho*/
void Swap(char &a, char &b)
{
    char temp = a;
    a = b;
    b = temp;
    return;
}

/*Ham in ra hoan vi ke tiep*/
string Inhoanvi(string mang, int n)
{
    string mangbandau = mang; // De so sanh tim hoan vi BIGGEST
    int i = n - 2;
    while(i>=0 && mang[i]>=mang[i+1]) i--;
    if (i>=0)
    {
        int k = n-1; // mang[k] la phan tu cuoi day
        while(mang[k] <= mang[i]) k--; // lui dan k de tim mang[k] dau tien lon hon mang[i]
        Swap(mang[k],mang[i]); // Doi cho mang[k] va mang [i]

        int a = i+1;
        int b = n-1;
        while(a<b)
        {
            Swap(mang[a],mang[b]);
            a++;
            b--;
        }
    }
    if (mangbandau == mang) mang = "BIGGEST"; // Neu sau khi hoa doi mak "mang" khong thay doi thi no la lon nhat
    return mang;
}
int main()
{
    int T;
    cin >> T; // T hoan vi

    vector<string> vt;
    vt.push_back(" "); // Bo gia tri vt[0], bat dau tinh tu vt[1] theo de bai.
    for (int i=1; i<=T; i++)
    {
        int temp;
        cin >> temp; // Doc du lieu thu tu bo test cua de bai -> Bo no di, khong can thiet
        string str;
        cin >> str;
        vt.push_back(str);
    }

    for (int i=1; i<=T; i++)
        cout << i << " " << Inhoanvi(vt[i],vt[i].length()) << endl;

    return 0;
}
