#include<bits/stdc++.h>
using namespace std;

int n,b;
vector<int> vt;

void inputData(){
    cin >> n >> b;
    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;
        vt.push_back(temp);
    }
}

// Tim max cua vt tu a toi b -> tra ve chi so cua so do trong vt
int indexMax(int a, int b){
    int imaxVt = a;
    for(int i=a; i<b; i++){
        if(vt[i] > vt[imaxVt]) imaxVt = i;
    }
    return imaxVt;
}


void solve(){
    inputData();

    int ans = -1;
    int imaxVt = indexMax(0,n);
    int imaxLeft = 0;
    int imaxRight = 0;

    for(int i=1; i<imaxVt; i++){
        imaxLeft = vt[imaxLeft] > vt[i]?imaxLeft:i;
        int temp1, temp2;
        temp2 = vt[imaxVt];
        temp1 = vt[imaxLeft];
        if(temp1-vt[i] >= b && temp2-vt[i] >= b){
            int signal = temp1 + temp2 - 2*vt[i];
            ans = max(ans,signal);
        }
     }

     for(int i=n-2; i>imaxVt; i--){
        imaxRight = vt[imaxRight] > vt[i]?imaxRight:i;
        int temp1, temp2;
        temp1 = vt[imaxVt];
        temp2 = vt[imaxRight];
        if(temp1-vt[i] > b && temp2-vt[i] > b){
            int signal = temp1 + temp2 - 2*vt[i];
            ans = max(ans,signal);
        }
    }

    cout << ans;
}

int main(){
    solve();
    return 0;
}
