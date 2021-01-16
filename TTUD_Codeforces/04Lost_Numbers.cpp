#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define dep(i,a,b) for(int i=(a);i>=(b);--i)
#define pb push_back
#define F first
#define S second
typedef long long ll;
const int maxn=(int)2e5+100;
typedef pair<int,int> pii;
int a[10]={4,8,15,16,23,42};
map<int,pii> mp;
int query(int l,int r){
	printf("? %d %d\n",l,r);
	int ans; cin>>ans;
	return ans;
}
int main(){
	rep(i,0,5) rep(j,i+1,5) mp[a[i]*a[j]]={a[i],a[j]};
	int ans[10][2],flag[110]={0,};
	int q[10];
	q[1]=query(1,1); q[2]=query(2,4); q[3]=query(3,5); q[4]=query(3,4);
	ans[1][0]=sqrt(q[1]);
	rep(i,2,4) ans[i][0]=mp[q[i]].F,ans[i][1]=mp[q[i]].S;
	int aa[10]; aa[1]=ans[1][0];
	rep(i,0,1) rep(j,0,1) if(ans[2][i]==ans[4][j]){
		aa[4]=ans[2][i];
		aa[2]=ans[2][0]*ans[2][1]/aa[4];
		aa[3]=ans[4][0]*ans[4][1]/aa[4];
		aa[5]=ans[3][0]*ans[3][1]/aa[3];
	}
	rep(i,1,5) flag[aa[i]]=1;
	rep(i,0,5) if(!flag[a[i]]) aa[6]=a[i];
	printf("!");
	rep(i,1,6) printf(" %d",aa[i]);
}
