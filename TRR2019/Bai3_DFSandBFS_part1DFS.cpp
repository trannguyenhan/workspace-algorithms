#include <iostream>
#include<string>
#include<fstream>
#include<string.h>
#include<stdlib.h>
#include<vector>
using namespace std;
/*Bai nay hien tai em moi lam moi phan a, phan b cua bai BFS la in ra quang duong ngan nhat tu dinh u toi dinh v em van chua lam a*/
typedef vector<string> TREE;
/*Kiem tra xem 2 dinh co phai la dinh ke*/
bool ktraDinhKe(string v1, string v2)
{
    int dem = 0;
    if (v1.length() != v2.length()) return false;
    for (int i=0; i<v1.length(); i++)
        if (v1.at(i) != v2.at(i)) dem++;
    if (dem == 1) return true;
    else
        return false;
}

/*Nhap du lieu vao tu file sgb-works.txt*/
void nhapDuLieu(char *filename, TREE &DS)
{
    ifstream f;
    f.open(filename);
    while (!f.eof()){
        string temp;
        f >> temp;
        DS.push_back(temp);
    }
    return;
}

/*Danh dau cac dinh da di qua - ban dau moi dinh deu chua di qua -> trang thai false*/
void Taovectordanhdau(vector<bool> &danhDau, int n)
{
    danhDau.resize(n, false);
    return;
}
/*Chay thuat toan tham lam dem so thanh phan lien thong cua do thi*/
void explore(TREE DS, vector<bool> &Ktra, int top)
{
    Ktra.at(top) = true;
    for (int i=0; i<DS.size(); i++)
    if (ktraDinhKe(DS.at(i),DS.at(top))){ // Neu top va i la hai dinh ke thi ....
        if (!Ktra.at(i)) explore(DS,Ktra,i); // Neu chua ghe tham qua i chay explore cua dinh i
    }
    return;
}
int  dfs(TREE DS, vector<bool> &Ktra)
{
    int cc = 0;
    for (int i=0; i<DS.size(); i++)
        if (!Ktra.at(i)){
            explore(DS,Ktra,i);
            cc = cc + 1;
        }
    return cc;
}
int main()
{
    TREE tree;
    nhapDuLieu("sgb-works.txt",tree);
    vector<bool> danhDau;
    Taovectordanhdau(danhDau,tree.size());
    int soTPLT = dfs(tree,danhDau); // Tra lai gia tri so thanh phan lien thong cua do thi cho bien soTPLT
    cout << soTPLT;
    /*
    for (int i=0; i<Top.size();i++)
        cout << Top.at(i) << " ";
    */
    return 0;
}
