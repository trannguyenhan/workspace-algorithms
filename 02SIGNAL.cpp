#include<bits/stdc++.h>
using namespace std;

// init variable
int n,b;
vector<int> vt;

void inputData(){
    cin >> n;
    cin >> b;

    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;
        vt.push_back(temp);
    }
}

// Tra ve chi so max cua day vt tu a toi b
int findMax(int a, int b){
    int im = a;
    for(int i=a; i<b; i++){
        if(vt[i] > vt[im]) im = i;
    }
    return im;
}

bool handlingLeft(int imax, int &signalmax){
    int foo = 0;
    int r = 0;
    for(int i=1; i<imax; i++){
        if(vt[foo] > vt[i] + b || vt[imax] > vt[i] + b){
            int signal = vt[foo] + vt[imax] - 2*vt[i];
            if(signal > signalmax) signalmax = signal;
        }

        r++;
        if(vt[r] > vt[foo]) foo = r;
    }

    if(signalmax != 0) return true;
    else return false;
}

bool handlingRight(int imax, int &signalmax){
    int foo = n-1;
    int r = n-1;
    for(int i=n-2; i>imax; i--){
        if(vt[foo] > vt[i] + b || vt[imax] > vt[i] + b){
            int signal = vt[foo] + vt[imax] - 2*vt[i];
            if(signal > signalmax) signalmax = signal;
        }

        r--;
        if(vt[r] > vt[foo]) foo = r;
    }

    if(signalmax != 0) return true;
    else return false;
}

void solve(){
    inputData();

    // Mot so ta can tim chac chan la so lon nhat cua day
    // Tim luon so do
    int imax = findMax(0,n);
    if(vt[imax] < b){
        cout << "-1"; // Neu tin hieu lon nhat < b => chac chan la 1 day
        return;
    }

    // Bay gio can kiem tra 2 ben cua imax
    int signalmaxLeft = 0, signalmaxRight = 0;
    if(handlingLeft(imax,signalmaxLeft) || handlingRight(imax,signalmaxRight)){
        cout << max(signalmaxLeft,signalmaxRight);
    }

}

int main(){
    solve();
    return 0;
}
