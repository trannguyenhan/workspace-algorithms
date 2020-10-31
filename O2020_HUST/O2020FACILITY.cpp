#include<bits/stdc++.h>
using namespace std;
const int MAX = 1000005;
struct donthue{
    int s; // Ngay bat dau thue
    int d; // So ngay thue
    int r; // So tien phai tra cho cong ty
};

int n,K;
donthue ds[MAX];
int x[MAX]; // danh sach cac khach hang thue hang
bool visited[MAX];
int tongTienMax = 0;
int tongTien = 0;
int ngayhientai = 0;
int ngaycuoicung;

bool comp(donthue a, donthue b){
    if(a.s < b.s) return true;
    return false;
}

int findLastDay(){
    int lastDay = 0;
    for(int i=0; i<n; i++)
        lastDay = max(lastDay,ds[i].s);
    return lastDay;
}

void inputData(){
    cin >> n >> K;
    for(int i=0; i<n; i++){
        cin >> ds[i].s >> ds[i].d >> ds[i].r;
    }
    sort(ds,ds+n,comp);
}

bool check(int a, int i){
    if(cnt >= 1) return false;
    if(ds[i].s > ngayhientai && !visited[i]) return true;
    return false;
}

void solution(){
    tongTienMax = max(tongTien,tongTienMax);
}

void TRY(int a){
    for(int i=0; i<n; i++){
        if(check(a,i)){
            x[a] = i;
            visited[i] = true;
            int ngaytruoc = ngayhientai;
            ngayhientai = ds[i].s + ds[i].d + K - 1;
            tongTien += ds[i].r;

            if(ngayhientai > ngaycuoicung) solution();
            else TRY(a+1);

            visited[i] = false;
            ngayhientai = ngaytruoc;
            tongTien -= ds[i].r;
        }
    }
}

int main(){
    inputData();
    ngaycuoicung = findLastDay();
    TRY(1);
    cout << tongTienMax;
    //cout << ngaycuoicung;
    return 0;
}
