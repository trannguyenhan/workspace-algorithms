#include<bits/stdc++.h>
using namespace std;
const int MAX = 1000001;
int S[MAX];
int pre[MAX];
long long A[MAX];
map<long long , vector<int> > pos;
int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
    int soTest;
    cin >> soTest;
    while(soTest > 0){
        int res = 0;
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> A[i];
            if(pos.count(A[i]) > 0)
                pos[A[i]].push_back(i);
            else {
                vector<int> a;
                a.push_back(i);
                pair<long long, vector<int> > temp = make_pair(A[i],a);
                pos.insert(temp);
            }
        }

        S[1] = 1;
        res = S[1];
        for(int i = 2; i <= n; i++){
            S[i] = 1;
            for(int j = 0; j < pos[A[i] -1].size(); j++){
                int v = pos[A[i] -1][j];
                if(j >= i){
                    continue;
                }
                else{
                    if(S[i] < S[v] + 1){
                        S[i] = S[v] + 1;
                        res = max(res,S[i]);
                    }
                }

            }
        }
        cout << res << endl;
        soTest --;
    }
}
