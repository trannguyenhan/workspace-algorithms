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

void permutationNext(){
    inputData();
    int lens = vt.size();

    int i = lens-2;
    while(i>=0 && vt[i] > vt[i+1]) i--;

    if(i<0){
        cout << "-1";
        return;
    }

    int j = lens-1;
    while(vt[j] < vt[i]) j--;

    swap(vt[j],vt[i]);
    int a = i+1;
    int b = lens-1;

    while(a<b){
        swap(vt[a],vt[b]);
        a++;
        b--;
    }

    for(int k=0; k<n; k++){
        cout << vt[k] << " ";
    }
}

int main(){
    permutationNext();
    return 0;
}
