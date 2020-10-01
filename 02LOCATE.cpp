#include<bits/stdc++.h>
using namespace std;
const int MAX = 1001;

int L,C;
vector<pair<int,int> > pre;
vector<pair<int,int> > last;


// tru 2 toa do cho nhau
pair<int,int> subXY(pair<int,int> X, pair<int,int> Y){
    int a = Y.first - X.first;
    int b = Y.second - X.second;
    return pair<int,int>(a,b);
}

void inputData(){
    cin >> L >> C;
    for(int i=0; i<L; i++)
        for(int j=0; j<C; j++){
            int temp;
            cin >> temp;
            if(temp == 1){
                pre.push_back(pair<int,int>(i,j));
            }
        }

    for(int i=0; i<L; i++)
        for(int j=0; j<C; j++){
            int temp;
            cin >> temp;
            if(temp == 1){
                last.push_back(pair<int,int>(i,j));
            }
        }
}

void solve(){
    inputData();

    int lensPre = pre.size();
    int lensLast = last.size();

    map<pair<int,int>, int> sl;
    int maxSl = 0;
    for(int i=0; i<lensPre; i++)
        for(int j=0; j<lensLast; j++){
            pair<int,int> sub = subXY(pre[i],last[j]);
            sl[sub]++;
            if(sl[sub] > maxSl) maxSl = sl[sub];
        }
    cout << maxSl << endl;

    pre.erase(pre.begin(),pre.end());
    last.erase(last.begin(),last.end());
}

int main(){
    int T;
    cin >> T;
    while(T>0){
        solve();
        T--;
    }
    return 0;
}
