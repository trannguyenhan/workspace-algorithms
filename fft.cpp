//http://e-maxx.ru/algo/fft_multiply
//copyright :))



#include<bits/stdc++.h>
using namespace std;

typedef vector<complex<double>> ar;

void fft (ar & a, int revert) {
	int n = (int)a.size();

	for (int i=1, j=0; i<n; ++i) {
		int bit = n >> 1;
		while(j>=bit){
			j =j- bit;
             bit=bit>>1;
        }
		j =j+ bit;
		if (i < j)
			swap (a[i], a[j]);
	}

	for (int len=2; len<=n; len<<=1) {
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
	if (revert==1)
		for (int i=0; i<n; ++i)
			a[i] /=n;
}
 vector<int>  multiplication (const vector<int> & a, const vector<int> & b) {
	ar ax (a.begin(), a.end()),  bx (b.begin(), b.end());
	int n = 1;
	while (n < max (a.size(), b.size()))  n =n<<1;
	n =n<<1;
	ax.resize (n);
    bx.resize (n);

	fft (ax, 0);
    fft (bx, 0);
	for (int i=0; i<n; ++i)
		ax[i] =ax[i]*bx[i];
	fft (ax, 1);
    vector<int>  result;
	result.resize (n);
	for (int i=0; i<n; i++)
		result[i] = int (ax[i].real() + 0.5);
    return result;
}



int main(){
    int m;
    cin>> m;
    int sizeA=m+1;
    vector<int> a(sizeA);
    for(int i=0;i<=(sizeA-1);i++){
        int tmp;
        cin>> tmp;
        a[i]=tmp;
    }

    cin>> m;
    int sizeB=m+1;
    vector<int> b(sizeB);
    for(int i=0;i<=(sizeB-1);i++){
        int tmp;
        cin>> tmp;
        b[i]=tmp;
    }

    vector<int> c =multiplication(a,b);

    int result =(int)(c[0]);
    for (int i = 1; i <= c.size(); i++) {
        result = result ^(int)(c[i]);
    }
     cout<< result;

    return 0;
}
