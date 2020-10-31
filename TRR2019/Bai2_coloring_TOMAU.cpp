#include <iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;

// Bai nay theo de bai thi cac dinh co thu tu tu 1, 2, 3, 4... va khong co dinh 0
// Nen trong bai nay em da dieu chinh de khong dung toi dinh 0 trong bai (giong voi vi du la khong co dinh 0 )

/*Nhap du lieu vao tu file*/
bool  inputdata(char *filename, vector<vector<int> > &vect, int &n, int &m)
{
    /*Khoi tao FILE myfile = filename*/
    ifstream myfile;
    myfile.open(filename);
    if (myfile.fail()){
        return false;
    }
    /*Doc du lieu tu file*/
    myfile >> n >> m; // Nhap vao so dinh va so canh
    vect.resize(n+1); // Cung cap luong bo nho cho vect la vector vect chua m vector khac
    int temp1, temp2; // Khai bao 2 bien temp1 va temp2 de luu tru gia tri tam thoi
    for (int i=0; i<m; i++){
        myfile >> temp1 >> temp2;
        vect[temp1].push_back(temp2); // Gan dinh temp2 la dinh ke cua dinh temp1
        vect[temp2].push_back(temp1); // Gan dinh temp1 la dinh ke cua dinh temp2
    }
    myfile.close();
    return true;
}

/*To mau mot dinh cua do thi*/
int tomau(vector<vector<int> > &vect, int top, int mau[], int n) // To 1 dinh cua do thi bang thuat toan tham lam
{
    int v;
    int i;
    int dem = 0;
    for (i=1; i<=n; i++){ // concept : thu tu mau nho nhat, mau nao ma khac tat cac cac mau cua cac dinh con lai thi dung chuong trinh
        for (v : vect[top]){
            if (i == mau[v]) dem = dem +1; // Neu gap mau trung thi dem tang them 1
        }
        if (dem == 0) break;
        dem=0;
    }
    return i;
}

/*To mau cac dinh cua do thi*/
void tomauALL(vector<vector<int> > vect, int n, int mau[])
{
    for (int i=1; i<=n; i++){
        mau[i] = tomau(vect,i,mau,n);
    }
    return;
}

/*In do thi ra file dothi.dot*/
void printdothidot(char *filename, int mau[],string color[], int n, int m)
{
    ofstream fileouput;
    fileouput.open(filename);
    fileouput << "graph dothi" << endl;
    fileouput << "{" << endl;
    for (int i=1; i<=n; i++){
        fileouput << " ";
        fileouput << i << " ";
        fileouput << "[fillcolor=" << color[mau[i]] << ", style=filled];" << endl;
    }

    ifstream fileinput;
    fileinput.open("dothi.txt");
    int temp1, temp2;
    fileinput >> temp1 >> temp2;
    for (int i=0; i<m; i++){
        fileinput >> temp1 >> temp2;
        fileouput << " ";
        fileouput << temp1 << " -- " << temp2;
        fileouput << endl;
    }
    fileouput << "}";
    return;
}
int main()
{
    int n, m; // n la so dinh cua do thi, m la so canh cua do thi
    // Tuc la, do thi G = (n,m)
    vector<vector<int> > dscanh;
    if (!inputdata("dothi.txt",dscanh,n,m)){
        cout << "FILE FAIL !!!" << endl;
        return -1;
    }
    int mau[n]; // n dinh se to toi da la n mau, dung mang mau[] de luu tru gia tri mau cua tung dinh
    // vi du : dinh 1 to mau 2 se co gia tri la mau[1] = 2

    /*bat dau to mau cu the nao ! neu muon nhieu mau hon thi them nhieu mau hon nha*/
    string color[39] = { "snow","red","green","blue","SlateBlue2","yellow","purple","gray","lawn green","YellowGreen","cyan","hot pink",
		"orange","snow1","khaki","SlateGray3","wheat","purple","pink1","VioletRed1","DarkCyan","black","LightGreen","DarkMagenta","DarkRed",
		"DarkCyan","DarkBlue","DarkGray","grey100","grey99","grey98","grey97","grey96","grey95","grey94","grey93","grey92","grey91","grey90"};
    /*Ket thuc chon mau o day nha ! */

    for (int i=0; i<n; i++) mau[i] = 0; // Tat ca cac dinh ban dau co mau la mau 0
    tomauALL(dscanh,n,mau);
    /*
    for (int i=1; i<=n; i++)
        cout << mau[i] << " ";
    */
    // Sau khi goi ham tomauALL la chung ta da to duoc mau 1, mau 2 cho canh. Gio chi can gan mau 1 la mau do, mau 2 la mau xanh ....
    //Bat dau nao !-----
    printdothidot("dothi.dot",mau,color,n,m);
    return 0;
}
