#include<bits/stdc++.h>
#define toado pair<int,int>
const int MAX = 50;
using namespace std;
bool visited[MAX];
int X[MAX]; // X[a] = b, danh dau con hau nam tai hang a va cot b
bool sum[MAX], sub[MAX];
map<toado, bool> holes; // vi tri cac ho
int n,m;
int cnt;

bool check(int a, int i){
    if(visited[i]) return false;
    if(holes[{a,i}]) return false;
    if(sum[a+i]) return false;
    if(sub[a-i]) return false;
    return true;
}

void solution(){
    cnt++;
}

// Vi con hau bat buoc phai nam o cac hang khac nhau nen gan moi hang vao moi cot
void TRY(int a){
    for(int i=0; i<n; i++){ // for tat ca cac cot co the gan cho hang a
        if(check(a,i)){
            X[a] = i; // hang a gan cho cot i <=> con hau nam o hang a va cot i
            visited[i] = true; // danh dau hang i da duoc chon
            sum[a+X[a]] = true;
            sub[a-X[a]] = true;

            if(a == n-1) solution();
            else TRY(a+1);

            visited[i] = false;
            sum[a+X[a]] = false;
            sub[a-X[a]] = false;
        }
    }
}

int main(){
    while(true){
        scanf("%d%d",&n,&m);
        if(n==0&&m==0) break;

        for(int i=0; i<m; i++){
            int temp1, temp2;
            scanf("%d%d",&temp1,&temp2);
            holes[{temp1-1,temp2-1}] = true;
        }

        cnt = 0;
        TRY(0);
        printf("%d\n",cnt);
        holes.erase(holes.begin(),holes.end());
    }

}
