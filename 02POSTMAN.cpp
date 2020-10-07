#include<bits/stdc++.h>
using namespace std;
const long long MAX = 10000005;
long long n,k;
long long mPos[MAX];
long long mNeg[MAX];

/*Tinh quang duong*/
long long qd(long long m[]){
    long long i = MAX - 1;
    unsigned long long tqd = 0; // Tong quang duong
    long long c = 0; // Luong du thua (so du)
    while(i>0){
        while(m[i] == 0 && i>0) i--;
        if(i == 0) break;

        long long thuong;
        m[i] = m[i] - c;
        if(m[i]<0){
            c = -m[i];
            m[i] = 0;
        } else {
            c = m[i] % k;
            if(c!=0) c = k - c;
            thuong = m[i] / k;
            if(c>0){
                tqd = tqd + 2*(thuong+1)*i;
            } else {
                tqd = tqd + 2*thuong*i;
            }

        }
        i--;
    }

    return tqd;
}

int main(){
    /*Doc du lieu*/
    cin >> n >> k;
    for(long long i=0; i<n; i++){
        long long temp1, temp2;
        cin >> temp1 >> temp2;
        if(temp1 > 0) mPos[temp1] = temp2;
        else {
            temp1 = abs(temp1);
            mNeg[temp1] = temp2;
        }
    }

    /*In ket qua*/
    cout << qd(mPos) + qd(mNeg);
    return 0;
}
