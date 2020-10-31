#include <iostream>
#include <math.h>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

// tao vector de luu cac gia tri lap phuong tim duoc
vector<long long> vt;

/*Tra ve gia tri lon nhat trong 1 vector*/
long long returnMax(vector<long long> vt)
{
    long long Max = 0;
    for(int i=0; i<vt.size(); i++)
        if(Max < vt[i]) Max = vt[i];
    return Max;
}

/*Ham kiem tra mot so co phai la so khoi lap phuong hay khong*/
bool kTraLP(long long N)
{
    // can bac 3 (n) = n ^ 1/3
    double lp = pow(N,1.0/3);
    int temp = (int)(lp+0.5);

    //cout << temp << endl;
    // Neu 1 so la lap phuong => (phan nguyen(can bac 3))^3 = chinh no
    if(temp*temp*temp == N) return true;
    else return false;
}

/*Tim so chu so cua 1 so*/
int soCS(long long N)
{
    if(N<0) return 0;
    if(N == 0) return 1;
    // Chia lien tiep cho 10 lay thuong toi khi nao duoc 0
    int dem = 0;
    while(N>0)
    {
        dem++;
        N = N / 10;
    }
    return dem;
}

/*Chuyen int -> string*/
// Su dung thu vien sstream
string convertToString(long long N)
{
    string temp;
    stringstream convert;
    convert << N;
    temp = convert.str();
    return temp;
}

/*Chuyen string -> int*/
// Su dung thu vien sstream
int convertToInt(string str)
{
    stringstream convert(str);
    int x = 0;
    convert >> x;
    return x;
}

/*Xoa di chu so tai vi tri i cua so N*/
long long delLocalI(int i, long long N)
{
    // Neu so chu so la 1 -> sau khi xoa se k con chu so nao
    if(soCS(N) == 1) return -1;
    if(i>soCS(N)) return 0;

    string tempStr = convertToString(N);
    tempStr.erase(i,1);
    long long tempInt = convertToInt(tempStr);
    return tempInt;
}

/*Bat dau kiem tra*/
void Try(long long N)
{
    int lens = soCS(N);
    for(int i=0; i<lens; i++)
    {
        if(kTraLP(N)) vt.push_back(N);
        if(lens>0)
        {
            N = delLocalI(i,N);
            Try(N);
        } else return;
    }
    return;
}

int main()
{
    int T;
    cin >> T;
    //if(kTraLP(T)) cout << "Dung";
    while(T>0)
    {
        long long N;
        cin >> N;

        Try(N);
        if(vt.size() == 0) cout << "-1";
        else cout << returnMax(vt);

        // Reset lai vt
        vt.erase(vt.begin(),vt.end());
        T--;
    }
    //N = delLocalI(5,N);
    //cout << N << endl;
    //cout << soCS(N);
    return 0;
}
