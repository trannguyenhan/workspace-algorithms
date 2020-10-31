#include <iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;

// Khai bao bien toan cuc
long long dem, sumT;

// Ham dem so to tien can de lay duoc so tien = S
void Dem(long long n, long long S, vector<long long> totien){
    if(n<0) return;

    sumT = totien[n] + sumT;
    dem++;

    if(sumT>S){
        sumT = sumT - totien[n];
        dem--;
        Dem(n-1,S,totien);
    } else if(sumT == S){
        return;
    } else {
        Dem(n-1,S,totien);
    }

    return;
}

int main()
{
    long long n, S;
    cin >> n >> S;
    vector<long long> totien;

    // Nhap gia tri
    for(long long i=0; i<n; i++){
        long long temp;
        cin >> temp;
        totien.push_back(temp);
    }

    // Sap xep vector totien
    sort(totien.begin(),totien.end());

    // Loai bo nhung to tien > S -> Giam thoi gian thuc hien chuong trinh
    int k;
    for(k=n-1; k>=0; k--){
        if(totien[k] <= S) break;
    }
    n = k;

    // Bat dau dem
    int demMin = 31;

    for (int i=n; i>=0; i--){
        sumT = 0;
        dem = 0;
        Dem(i,S,totien);

        if((dem<demMin) && (dem>0) && (sumT == S)) {
            demMin = dem;
        }
    }

    // Print result
    if(demMin<=30) cout << demMin;
    else cout << "-1";

    return 0;
}
