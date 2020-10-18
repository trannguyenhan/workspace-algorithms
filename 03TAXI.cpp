#include<bits/stdc++.h>
using namespace std;
const int MAX = 30;
int n;
int c[MAX][MAX];
bool visited[MAX];
int x[MAX]; // Luu tru cac vi tri da di
int distMin = 2147483647;
int distCur = 0;
int minC = 0;
int passengers = 0;

void inputData(){
    cin >> n;
    for(int i=0; i<=2*n; i++)
        for(int j=0; j<=2*n; j++){
            cin >> c[i][j];
        }
}

int findMin(){
    int minC = 2147483647;
    for(int i=0; i<=2*n; i++)
        for(int j=0; j<=2*n; j++)
            if(c[i][j] != 0)
                minC = min(minC,c[i][j]);
    return minC;
}

bool check(int a, int i){
    if(passengers==1)
        if(i<=n) return false;
    if(i > n)
        if(!visited[i-n]) return false;
    if(c[x[a-1]][i] == 0) return false;
    if(!visited[i]) return true;
    return false;
}

void solution(){
    int distAll = distCur + c[x[2*n]][0];
    distMin = min(distMin,distAll);
}

void TRY(int a){
    for(int i=1; i<=2*n; i++){
        if(check(a,i)){
            x[a] = i;
            visited[i] = true;
            distCur += c[x[a-1]][i];
            if(i>n)
                passengers--;
            else passengers++;

            if(a == 2*n) solution();
            else
                if(distCur + minC*(2*n-a) < distMin) TRY(a+1);

            visited[i] = false;
            distCur -= c[x[a-1]][i];
            if(i>n)
                passengers++;
            else passengers--;
        }
    }
}

int main(){
    inputData();
    x[0] = 0;
    minC = findMin();
    TRY(1);
    cout << distMin;
    //cout << minC;
    return 0;
}
