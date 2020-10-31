#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

/*Ham so sanh x^y va y^x, neu x^y > y^x -> true, nguoc lai -> false*/
bool soSanh(int x, int y)
{
    double bt1 = y*log(double(x));
    double bt2 = x*log(double(y));

    if(bt1 > bt2) return true;
    else return false;
}

/*Dem so cap x,y tuong ung*/
int demSoCap(vector<int> vtX, vector<int> vtY, int n, int m)
{
        int dem = 0;
        for (int i=0; i<n; i++)
            for (int j=0; j<m; j++)
                if(soSanh(vtX.at(i),vtY.at(j))) dem++;

        return dem;
}

int main()
{
    vector<int> vtX, vtY;
    int T, n, m;
    cin >> T >> n >> m;

    while(T>0)
    {
        // Nhap gia tri cho mang X[]
        for (int i=0; i<n; i++)
        {
            int temp;
            cin >> temp;
            vtX.push_back(temp);
        }

        // Nhap gia tri cho mang Y[]
        for (int i=0; i<m; i++)
        {
            int temp;
            cin >> temp;
            vtY.push_back(temp);
        }

        cout << demSoCap(vtX,vtY,n,m);
        T--;
    }

    return 0;
}
