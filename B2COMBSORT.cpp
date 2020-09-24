#include<bits/stdc++.h>

using namespace std;

vector<double> input(double n){
    vector<double> vt;
    for(double i=0; i<n; i++){
        double temp;
        cin >> temp;
        vt.push_back(temp);
    }

    return vt;
}

void prdoubleResult(vector<double> vt, double n){
    for(double i=0; i<n; i++){
        cout << vt[i] << " ";
    }

    return;
}

int main(){
    double n;
    vector<double> vt;

    cin >> n;
    vt = input(n);

    sort(vt.begin(),vt.end());

    prdoubleResult(vt,n);


    return 0;
}
