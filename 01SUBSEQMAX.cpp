#include <iostream>
#include<vector>

using namespace std;

int subSEQMax(vector<int> vt, int n){
    int sum = 0;
    int maxSum = 0;

    for(int i=0; i<n; i++){
        sum = sum + vt[i];
        if(sum < 0){
            sum = 0;
        } else {
            if(sum > maxSum) maxSum = sum;
        }
    }
    return maxSum;
}

int main()
{
    int n;
    vector<int> vt;

    cin >> n;
    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;
        vt.push_back(temp);
    }

    cout << subSEQMax(vt,n);
    return 0;
}
