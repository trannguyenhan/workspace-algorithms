#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> vt;

void inputData(){
    cin >> n;
    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;
        vt.push_back(temp);
    }
}

int findMin(int a, int b){
    int minarr = vt[a];

    for(int i=a+1; i<b; i++){
        if(vt[i]<minarr) minarr = vt[i];
    }

    return minarr;
}

void handling(){
    if(n==0) return;
    int minS = 0;
    for(int i=0; i<n; i++)
        for(int j=i; j<n; j++){
            int minarr = findMin(i,j+1);
            int minST = minarr * (j+1-i);
            if(minST > minS) minS = minST;
        }
    cout << minS << endl;
    vt.erase(vt.begin(),vt.end());
}

void solve(){

    do{
        inputData();
        handling();
    } while(n!=0);

}

int main(){

    solve();
    return 0;
}
