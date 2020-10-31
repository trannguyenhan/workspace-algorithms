#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

const int MAX = 200;
int arr[MAX]; // 2 <= S,P <= 200
vector<vector<int> > vt;
int dem = 0;


/*Ham kiem tra mot so la so nguyen to hay khong*/
bool kTraSNT(int N)
{
    if (N<=1) return false;
    else
    {
        for (int i=2; i<=sqrt(N); i++)
            if (N%i == 0) return false;
    }
    return true;
}

/*In ket qua*/
void printResult(int N)
{
    vt.resize(dem+1);
    for (int i=0; i<N; i++)
        vt[dem].push_back(arr[i]);
    return;
}

/*Tinh tong*/
// Muc dich : de xem tong cac so nguyen to sau P cua minh da bang S chua?
int sumResult(int N)
{
    int sum = 0;
    for (int i=0; i<N; i++)
        sum = sum + arr[i];
    return sum;
}

/*Dua ra N so nguyen to sau P co tong la S*/
void Try(int a, int N, int P, int S)
{
    for (int i=P+1; i<=S; i++)
        if (kTraSNT(i))
        {
                arr[a-1] = i;
                if (a==N)
                {
                    if (sumResult(a) == S)
                    {
                        printResult(a);
                        dem++;
                    }
                } else Try(a+1,N,i,S);
        }
    return;
}

int main()
{
    int T;
    int N, P, S;
    cin >> T;
    while(T>0)
    {
        dem = 0;
        cin >> N >> P >> S;
        Try(1,N,P,S);

        cout << vt.size() << endl;
        for (int i=0; i<vt.size(); i++)
        {
            for (int j=0; j<vt[i].size(); j++)
                cout << vt[i][j] << " ";
            cout << endl;
        }

        vt.erase(vt.begin(), vt.end());
        T--;
    }
    return 0;
}
