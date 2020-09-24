#include<bits/stdc++.h>

using namespace std;

vector<int> input(int n){
    vector<int> vt;
    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;
        vt.push_back(temp);
    }

    return vt;
}

void printResult(vector<int> vt, int n){
    for(int i=0; i<n; i++){
        cout << vt[i] << " ";
    }

    return;
}

int main(){
    int n;
    vector<int> vt;

    cin >> n;
    vt = input(n);

    sort(vt.begin(),vt.end());

    printResult(vt,n);


    return 0;
}
