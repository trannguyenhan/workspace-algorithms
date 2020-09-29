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

    int summax = 0;
    for(int i=0; i<n; i++){
        int pre;
        int last;

        // pre la chi so dau tien ben trai i ma vt[pre] < vt[i]
        for(pre=i; pre>=0; pre--){
            if(vt[pre] < vt[i]) break;
        }

        // last la chi so dau tien ben phai ma vt[last] < vt[i]
        for(last=i; last<n; last++){
            if(vt[last] < vt[i]) break;
        }

        int sum = (last - pre - 1) * vt[i];
        if(sum > summax) summax = sum;
    }


    cout << summax << endl;
}

void solve(){

    do{
        inputData();
        handling();
        vt.erase(vt.begin(),vt.end());
    } while(n!=0);

}

int main(){

    solve();
    return 0;
}
