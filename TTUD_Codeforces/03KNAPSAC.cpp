#include<bits/stdc++.h>
using namespace std;
const int MAX = 101;

struct dovat{
    int trongluong;
    int giatri;
};
int n, b;
dovat ds_dovat[MAX];
bool visited[MAX]; // Danh dau cac tui da duoc lay
int X[MAX]; // Luu tru gia tri
int tongTrongLuong = 0;
int tongGiaTri = 0;
int tongGiaTriLonNhat = 0;

/*Nhap du lieu va sap xep lai do vat theo thu tu giam dan cua giatri/trongluong*/
// Tao ham so sanh sao cho giatri/trongluong giam dan
bool comp(dovat a, dovat b){
    if(a.giatri/a.trongluong > b.giatri/b.trongluong) return true;
    else return false;
}
void inputData(){
    cin >> n >> b;
    for(int i=0; i<n; i++){
        cin >> ds_dovat[i].trongluong;
        cin >> ds_dovat[i].giatri;
    }
    sort(ds_dovat,ds_dovat+n,comp);
}

bool check(int a, int i){
    return true;
}

void solution(int a){
    tongGiaTri -= ds_dovat[a].giatri;
    tongGiaTriLonNhat = max(tongGiaTriLonNhat,tongGiaTri);
    tongGiaTri += ds_dovat[a].giatri;
}

void TRY(int a){
    for(int i=0; i<=1; i++){
        if(check(a,i)){
            X[a] = i;
            if(i != 0){
                tongTrongLuong += ds_dovat[a].trongluong;
                tongGiaTri += ds_dovat[a].giatri;
            }

            if(tongTrongLuong > b || a == n) solution(a);
            else TRY(a+1);

            if(i != 0){
                tongTrongLuong -= ds_dovat[a].trongluong;
                tongGiaTri -= ds_dovat[a].giatri;
            }
        }
    }
}

int main(){
    inputData();
    TRY(0);
    cout << tongGiaTriLonNhat;
    return 0;
}
