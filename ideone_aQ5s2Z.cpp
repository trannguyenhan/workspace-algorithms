#include<bits/stdc++.h>
#define ll long long
ll Mod = 1e15 +7;
using namespace std;
ll tribo(ll n){
	if (n == 1) return 1;
	if (n == 2) return 2;
	if (n == 3) return 3;
	int a1 = 1, a2 = 2, a3 = 3;
	int i = 4;
	int a;
	while (i<=n)
    {
        a = a1 + a2 + a3;
        a1 = a2;
        a2 = a3;
        a3 = a;
        i++;
    }
    return a;
}
ll sum(ll n){
    ll sum = 0;
	sum = ((tribo(n+2)+tribo(n))/2 - 1) % Mod;
	return sum;
}
int main(){
	int t;
	cin >> t;

    vector<ll> vt;
	for (int i=0; i<t; i++)
    {
		ll temp;
		cin >> temp;
		vt.push_back(temp);
    }

    for (int i=0; i<t; i++)
        cout << sum(vt[i]) << endl;

	return 0;
}
