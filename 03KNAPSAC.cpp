#include<bits/stdc++.h>
#define dovat pair<int,int>
using namespace std;
const int MAX = 40;

int n,b;
// dovat.first = trong luong, dovat.second = gia tri su dung
dovat arr[MAX];

bool comp(dovat a, dovat b){
    if(a.second > b.second) return true;
    else return false;
}

void printResult(){
    for(int i=0; i<n; i++)
        cout << arr[i].first << " " << arr[i].second << endl;
    return;
}

int main(){
    cin >> n >> b;
    for(int i=0; i<n; i++){
        cin >> arr[i].first;
        cin >> arr[i].second;
    }

    sort(arr,arr+n,comp);

    int sum = 0;
    int tgtMax = 0;
    int tgt = 0;
    for(int i=0; i<n; i++){
        sum = sum + arr[i].first;
        if(sum < b){
            tgt = tgt + arr[i].second;
            continue;
        }
        else {
            tgtMax = max(tgtMax,tgt);
            sum = sum - arr[i].first;
            continue;
        }
    }

    cout << tgtMax;
    return 0;
}
