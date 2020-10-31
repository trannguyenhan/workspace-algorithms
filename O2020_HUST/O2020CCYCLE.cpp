#include<bits/stdc++.h>
using namespace std;
int n,L,s,t;
vector<vector<int> > dske;
int cnt = 0;
int cntDist = 0;

void inputData(){
    cin >> n >> L >> s >> t;
    dske.resize(3*n+1);
    for(int i=1; i<=3*n; i++){
        if(i == 1){
            dske[i].push_back(3*n); dske[3*n].push_back(i);
            dske[i].push_back(i+1); dske[i+1].push_back(i); // ##
            dske[i].push_back(i+2); dske[i+2].push_back(i); // ##
        } else if(i % 3 == 1){
            dske[i].push_back(i-1); dske[i-1].push_back(i); // Dinh i ke i-1, dinh i-1 ke dinh i
            dske[i].push_back(i+1); dske[i+1].push_back(i); // ##
            dske[i].push_back(i+2); dske[i+2].push_back(i); // ##
        }
    }
}

void solution(int e){
    if(e == t) cntDist++;
}

void TRY(int s){
    for(int i=0; i<dske[s].size(); i++){
        if(cnt <= L){
            cnt++;
            if(cnt == L) solution(dske[s].at(i));
            else TRY(dske[s].at(i));
            cnt--;
        }
    }
}

int main(){
    inputData();
    TRY(s);
    cout << cntDist;
    return 0;
}
