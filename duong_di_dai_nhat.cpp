#include <iostream>
#include <vector>
using namespace std;
typedef vector<vector<int> > Tree;
const int MAX = 20;
int dem = 0;

/**
    Y tuong tao cay : tao 1 vector 2 chieu de luu tru cay voi cac gia tri nhu sau
    vt[0][*] : dai dien cho dinh 0, voi vt[0][0] = a => dinh 0 ke voi dinh a
                                        vt[0][1] = b => dinh 0 ke voi dinh b
                                        ....
    De don gian ta chi xet do thi lien thong, boi vi viec tim cac thanh phan lien thong cua do thi la rat don gian roi =))
*/

/*Danh dau cac canh da duoc di qua*/
bool danhDau[MAX][MAX]; // Vi du : canh {2;3} da di qua => danhDau[2][3] = danhDau[3][2] = true
int Max = 0;

/*Bat dau duyet*/
void duyetCanhDinh(Tree vt, int top)
{
    for (int i=0; i<vt[top].size(); i++)
    {
        int iTop = vt[top][i]; // Dat lai cho gon, tai khong dung duoc for each

        if (!danhDau[top][iTop])
        {
            danhDau[top][iTop] = true;
            danhDau[iTop][top] = true;
            dem++;
            duyetCanhDinh(vt,iTop);
        }
    }

    if (Max < dem) Max = dem;
    if (dem > 0) dem--;

    return;
}

int main()
{
    int N, M;
    cin >> N >> M;
    Tree vt(N);

    // Cac canh ban dau deu chua di qua
    for (int i=0; i<MAX; i++)
        for (int j=0; j<MAX; j++)
            danhDau[i][j] = false;

    for (int i=0; i<M; i++)
    {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        vt[temp1].push_back(temp2); // Gan dinh temp2 ke voi dinh temp1
        vt[temp2].push_back(temp1); // Gan dinh temp1 ke voi dinh temp2
    }


    for (int i=0; i<vt.size(); i++)
    {
        cout << i << ".  ";
        for (int j=0; j<vt[i].size(); j++)
            cout << vt[i][j] << " ";
        cout << endl;
    }


    duyetCanhDinh(vt,0);
    cout << Max << endl;
    return 0;
}

