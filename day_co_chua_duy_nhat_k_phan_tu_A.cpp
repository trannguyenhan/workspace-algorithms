#include <iostream>
#include<vector>
using namespace std;

int N;
int k;
int demtong = 0;
vector<char> str;

/*Kiem tra xau bat ki (N+k phan tu) co k phan tu A lien tiep duy nhat khong ?*/
bool ktraXAU(vector<char> xau)
{
    int i=0;
    int demSlg = 0;
    while(i<N+1)
    {
        if (xau[i] == 'A')
        {
            int dem=0;
            for (int j=i; j<i+k; j++) if (xau[j] == 'A') dem++;
            if (dem == k) demSlg++;
        }
        i++;
    }
    if (demSlg==1) return true;
    return false;
}

/*In ket qua*/
void printresult(vector<char> xau)
{
    for (int i=0; i<N+k; i++)
        cout << xau[i];
    cout << endl;
    return;
}

/*Xu li*/
void setup(vector<char> &xau)
{
    int i=0;
    vector<char> tonghopxau;
    while(i<=N)
    {
        if (i==0)
        {
            // Th1 : k phan tu A nam dau;
            for (int j=0; j<k; j++) tonghopxau.push_back('A');
            for (int j=0; j<N; j++) tonghopxau.push_back(xau[j]);
            if(ktraXAU(tonghopxau)) printresult(tonghopxau);
        }
        else
        {
            // Th2 : con lai
            for (int j=0; j<=i-1; j++) tonghopxau.push_back(xau[j]);
            for (int j=0; j<k; j++) tonghopxau.push_back('A');
            for (int j=i; j<N; j++) tonghopxau.push_back(xau[j]);
            if (ktraXAU(tonghopxau)) printresult(tonghopxau);
        }
        i++;
        tonghopxau.clear();
    }
    return;
}

/*Quay lui*/
void Try(int a)
{
    if (a>N)
        setup(str);
    for (char i = 'A'; i<= 'B'; i++)
    {
        str[a-1] = i;
        if (a<=N) Try(a+1);
    }
    return;
}

int main()
{
    cin >> N >> k;
    N=N-k;          // Chi can tim N-k day tao tu A va B, k phan tu con lai la k phan tu A dai lien tiep
    str.resize(N);  // Cap phat N bo nho cho str

    
    Try(1);
    return 0;
}
