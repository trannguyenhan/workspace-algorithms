#include<bits/stdc++.h>
using namespace std;

typedef complex<double> base;
typedef vector<base> vb;

void input(int &n, int &m, vb &x, vb &y){
    cin >> n;
    for(int i=0; i<=n; i++){
        int tmp;
        cin >> tmp;

        base mycomplex(tmp,0);
        x.push_back(mycomplex);
    }

    cin >> m;
    for(int i=0; i<=m; i++){
        int tmp;
        cin >> tmp;

        base mycomplex(tmp,0);
        y.push_back(mycomplex);
    }
}

void fft(vb & a, bool revert){
	int n = (int)a.size();

	for(int i=1, j=0; i<n; ++i){
		int bit = n >> 1;
		while(j>=bit){
			j =j- bit;
             bit=bit>>1;
        }
		j =j+ bit;
		if (i < j)
			swap (a[i], a[j]);
	}

	for(int len=2; len<=n; len<<=1){
		double ang = 2*M_PI/len;
        if(revert==1) ang=-ang;
		complex<double> wlen (cos(ang), sin(ang));
		for (int i=0; i<n; i+=len) {
			complex<double> w (1);
			for (int j=0; j<len/2; ++j) {
				complex<double> u = a[i+j],  v = a[i+j+len/2] * w;
				a[i+j] = u + v;
				a[i+j+len/2] = u - v;
				w =w * wlen;
			}
		}
	}
	if(revert==1)
		for(int i=0; i<n; ++i)
			a[i] /=n;
}

int multiPly(int n, int m, vb x, vb y){
    int p = 1;
	while(p < max (n, m)) p=p<<1;
	p=p<<1;
	x.resize(p);
    y.resize(p);

	fft(x, false);
    fft(y, false);

    vector<base> h(p);
	for (int i=0; i<p; i++)
		h[i] =x[i]*y[i];

	fft (h, true);

	int res = (int)(real(h[0])+0.5);
	for (int i=1; i<=p; i++){
		res = res ^ (int)(real(h[i])+0.5);
	}

    return res;
}

int main(){
    int n, m;
    vector<base> x,y;
    input(n,m,x,y);
    cout << multiPly(n,m,x,y);
}
