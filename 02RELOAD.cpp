#include<bits/stdc++.h>

using namespace std;

int n;
vector<int> vt;
int dgg;

// Tim do gap ghenh cua duong di trong lan dau tien
void findDGG(){
    dgg = 1;
    for(int i=1; i<n; i++){
        if(vt[i] != vt[i-1]) dgg++;
    }
}

// Doc vao do gap ghenh cua duong ban dau
void inputData1(){
    cin >> n;
    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;
        vt.push_back(temp);
    }
    findDGG(); // dua vao do gap ghenh tai thoi diem hien tai (dgg)
}

// Ham xu ly do gap ghenh cua duong di sau moi lan thay doi
void handling(int temp1, int temp2){
    temp1--;

    int TFirst = 1; // Do gap ghenh tai doan [temp1-1,temp1+1] luc chua thay doi
    if(vt[temp1] != vt[temp1-1] && temp1-1 >= 0) TFirst++;
    if(vt[temp1+1] != vt[temp1] && temp1+1 < n) TFirst++;

    int TSecond = 1; // DO gan ghenh tai doan [temp1-1,temp1+1] luc da sua doi
    vt[temp1] = temp2; // sua lai duong temp1 bang loai nhua temp2
    if(vt[temp1] != vt[temp1-1] && temp1-1 >= 0) TSecond++;
    if(vt[temp1+1] != vt[temp1] && temp1+1 < n) TSecond++;

    int T = TSecond - TFirst;
    dgg = dgg + T;

    cout << dgg << endl;

}

// Doc nhung thay doi va xu ly tung thay doi
void inputData2(){
    int q;
    cin >> q;
    for(int i=0; i<q; i++){
        int temp1;
        int temp2;

        cin >> temp1 >> temp2;

        // Xu ly tung test va dua ra ket qua
        handling(temp1,temp2);
    }
}
int main(){

    inputData1();
    inputData2();
    return 0;
}
