#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*Tra lai STT cua phan tu co gia tri cho truoc*/
int findElement(vector<long long> vt, long long pt)
{
    int lens = vt.size();
    int vitri;

    for(int i=0; i<lens; i++)
    {
        if(vt[i] == pt)
        {
            vitri = i;
            break;
        }
    }

    return vitri;
}


int soCapNghichThe(vector<long long> vtA, vector<long long> vtB)
{
    int dem = 0;
    for(int i=0; i<vtA.size(); i++)
    {
        int vitri = findElement(vtB,vtA[i]);
        dem = dem + vitri;

        // Ket thuc moi vong lap xoa di cac phan tu da xet
        //vtA.erase(vtA.begin());
        vtB.erase(vtB.begin()+vitri);
    }
    return dem;
}

int main()
{
    int T;
    int N;
    vector<long long> vtA;

    cin >> T;
    while(T>0)
    {
        cin >> N;
        for(int i=0; i<N; i++)
        {
            int  temp;
            cin >> temp;
            vtA.push_back(temp);
        }

        vector<long long> vtB(vtA); // Tao 1 vector B la ban sao cua vector A
        sort(vtB.begin(),vtB.end()); // Xap xep lai vector B


        cout << soCapNghichThe(vtA,vtB) << endl;

        // Xoa toan bo vector khi ket thuc 1 vong lap
        vtA.erase(vtA.begin(),vtA.end());
        //vtB.erase(vtB.begin(),vtB.end());
        T--;
    }
    return 0;
}
