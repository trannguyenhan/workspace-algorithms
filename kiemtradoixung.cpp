#include<bits/stdc++.h>
using namespace std;

bool kt(int a[], int l, int r){
    if(l >= r) return true;
    if(a[l] != a[r]) return false;
    return kt(a, l+1, r-1);
}

int main(){
    int a[100] = {1,2,2,1};
    if(kt(a,0,3)) cout << "DUNG";
    else cout << "SAI";
}
