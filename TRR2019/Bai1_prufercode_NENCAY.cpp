#include <iostream>
#include<vector>
using namespace std;
typedef vector<vector<int> > Tree;

/*Tinh bac cua 1 dinh*/
int deg(Tree vect, int node)
{
    return vect[node].size(); // Bac cua 1 dinh i la bang so luong phan tu cua vector vect[i]
}

/*Xoa 1 canh lien ket voi dinh node*/
void Deledge(Tree &vect, int node)
{
    // Sau khi xoa dinh node ta can xoa tat ca cac canh nao ma dinh node noi toi
    for (int i=0; i<vect.size(); i++)
        for (int j=0; j<vect[i].size(); j++)
            if (vect[i][j] == node) vect[i].erase(vect[i].begin()+j);
    return;
}

/*Xoa 1 dinh*/
void Delnode(Tree &vect, int node)
{
    vect[node].clear(); // Dua kich thuoc dinh node ve 0 <=> da xoa dinh node
    Deledge(vect,node); // Sau khi xoa dinh node xoa cac canh ma dinh node noi toi <=> goi hamm Deledge da cai dat
    return;
}

/*Kiem tra so dinh con lai*/
int Demnode(Tree vect)
{
    // Do minh chi coi dinh bi xoa la co kich thuoc = 0 vay can 1 ham de dem so dinh chua bi xoa <=> kich thuoc khac 0
    int sum = 0;
    for (int i=0; i<vect.size(); i++)
        if (deg(vect,i) > 0) sum++;
    return sum;
}

/* vector<int> luutru; // Luu tru lai ma prufer code */
/*In ma prufer code*/
void printprufercode(Tree vect)
{
    int i;
    /*
    if (Demnode(vect) == 1) // Neu chi con dinh 0 thi in ra
    {
        for (i=0; i<luutru.size(); i++)
            cout << luutru[i] << " ";
    }
    */
    if (Demnode(vect) > 2) // Van chua xoa het dinh thi tiep tuc xoa tiep
    {
        /*
        for (i=0; i<vect.size(); i++)
        cout << deg(vect,i) << " ";
        cout << endl;
        */

        for (i=1; i<vect.size(); i++)
            if (deg(vect,i) == 1) break; // Tim dinh co bac nho nhat voi nhan nho nhat
        int v = vect[i][0]; /* luutru.push_back(v); */
        cout << v << " "; // In ma prufer code la dinh ke voi dinh bi xoa
        Delnode(vect,i);
        printprufercode(vect);
    }
    return;
}
int main()
{
    int edge;
    int allnode; // allnode = so dinh || allnode = edge + 1
    cin >> edge;
    allnode = edge + 1;

    /*Dung 1 vector 2 chieu lam danh sach ke cua cac dinh*/
    Tree vect;
    vect.resize(allnode); // can luu tru allnode vector vect[1], vect[2], ..., vect[allnode].

    /*Gan danh sach ke cho cac dinh tu ban phim*/
    for (int i=0; i<edge; i++)
    {
        int v1; // value 1
        int v2; // value 2
        cin >> v1;
        cin >> v2;
        vect[v1].push_back(v2);  // Gan v2 vao lam dinh ke cho v1
        vect[v2].push_back(v1);  // Gan v1 vao lam dinh ke cho v2
    }
    /*
    for (int i=0; i<allnode; i++)
        cout << deg(vect,i);
        cout << endl;
        cout << vect.size() << endl;
    Delnode(vect,0);
    for (int i=0; i<allnode; i++)
        cout << deg(vect,i);
        cout << endl;
        cout << vect.size();
    */
    printprufercode(vect);
    return 0;
}
