#include<bits/stdc++.h>
using namespace std;
const int MAX = 20;
int N,M;
int c[MAX];
vector<vector<int> > A;
int course[MAX];
int maxLoadAllPeriods = 0;
int minAll = 2147483647;
int theLoadOfPeriods[MAX];

void inputData(){
    cin >> N >> M;
    for(int i=0; i<N; i++)
        cin >> c[i];
    A.resize(N+1);

    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++){
            int temp;
            cin >> temp;
            if(temp != 0){
                A[j].push_back(i);
            }
        }
}

bool check(int a, int i){ // Khoa hoc a, ki i
    for(int j=0; j<A[a].size(); j++){
            if(course[A[a].at(j)] == i) return false;
    }
    return true;
}

void solution(){
    //cout << maxLoadAllPeriods << endl;
    minAll = min(minAll,maxLoadAllPeriods);
}

void TRY(int a){
    for(int i=0; i<M; i++){
        if(check(a,i)){
            course[a] = i; // Khoa hoc a chi dinh vao ki i
            theLoadOfPeriods[i] += c[a];
            int pre = maxLoadAllPeriods;
            maxLoadAllPeriods = max(maxLoadAllPeriods,theLoadOfPeriods[i]);

            if(a==N) solution();
            else
                if(maxLoadAllPeriods < minAll) TRY(a+1);

            maxLoadAllPeriods = pre;
            theLoadOfPeriods[i] -= c[a];
        }
    }
}

int main(){
    inputData();
    TRY(0);
    cout << minAll;
    return 0;
}
