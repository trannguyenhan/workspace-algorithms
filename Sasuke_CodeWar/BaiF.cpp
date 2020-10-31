#include <iostream>
#include<vector>
#include<algorithm>
#include<fstream>
#include<math.h>
#include<sstream>

using namespace std;


int maxDiff(int n, int k, vector<int> a){
    sort(a.begin(),a.end());

    int sum1 = 0;
    int sum2 = 0;

    for(int i=0; i<k; i++)
        sum1 = sum1 + a[i];
    for(int i=k; i<n; i++)
        sum2 = sum2 + a[i];

    int kq1 = abs(sum1-sum2);

    sum1 = 0; sum2 = 0;
    for(int i=0; i<n-k; i++)
        sum1 = sum1 + a[i];
    for(int i=n-k; i<n; i++)
        sum2 = sum2 + a[i];

    int kq2 = abs(sum1-sum2);

    return min(kq1,kq2);
}

int main()
{

    return 0;
}
