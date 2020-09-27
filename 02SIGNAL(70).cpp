#include<bits/stdc++.h>
using namespace std;
/*
    --> 70 point
*/
// init variable
int n,b;
vector<int> vt;

void initVariable(){
    cin >> n;
    cin >> b;

    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;
        vt.push_back(temp);
    }
}

// return index of max in vector
int indexMaxOfVector(int a, int b){
    int indexMax = 0;
    for(int i=a; i<b; i++){
        if(vt[i] > vt[indexMax]) indexMax = i;
    }
    return indexMax;
}

// check pos cut
bool checkPosCut(int index){
    int indexMax1 = indexMaxOfVector(0,index);
    int indexMax2 = indexMaxOfVector(index+1,vt.size());

    if(vt[indexMax1]-vt[index] >= b && vt[indexMax2]-vt[index] >= b) return true;
    else return false;
}

// return signal mesurement
int signalMesurement(int index){
    int indexMax1 = indexMaxOfVector(0,index);
    int indexMax2 = indexMaxOfVector(index+1,vt.size());

    return vt[indexMax1] + vt[indexMax2] - vt[index]*2;
}

// check array
void signalMain(){
    for(int i=0; i<n; i++){
        if(checkPosCut(i)){
            int maxS = 0;
            for(int i=0; i<n; i++){
                int temp = signalMesurement(i);
                if(temp > maxS) maxS = temp;
            }
            cout << maxS;
            return;
        }
    }
    cout << "-1";
}

int main(){

    initVariable();
    signalMain();

    return 0;
}
