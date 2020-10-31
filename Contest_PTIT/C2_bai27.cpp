#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool search(vector<int> groups, int row, vector<int> &vt, int target)
{
    if(row<0) return true;
    int v = vt[row--];
    for(int i=0; i<groups.size(); i++)
    {
        if(groups[i]+v <= target)
        {
            groups[i] += v;
            if(search(groups,row,vt,target)) return true;
            groups[i] -= v;
        }
        if(groups[i] == 0) break;
    }
    return false;
}

bool canPartitionKSubsets(vector<int> &vt, int K)
{
    int sum = 0;
    for (int i=0; i<vt.size(); i++)
        sum = sum + vt[i];

    // Neu Tong(vt) khong chia het cho K => false
    if (sum % K > 0) return false;
    int target = sum / K;

    int row = vt.size()-1;
    if(vt[row] > target) return false; // Neu gia tri lon nhat trong mang > target => khong chon duoc cap phu hop
    while((row>=0) && (vt[row] == target))
    {
        row--;
        K--;
    }

    vector<int> groups(K);
    return search(groups,row,vt,target);
}

int main()
{
    int T;
    int N, K;
    vector<int> vt;
    cin >> T >> N >> K;

    while(T>0)
    {
        for (int i=0; i<N; i++)
        {
            int temp;
            cin >> temp;
            vt.push_back(temp);
        }

        // Sap xep lai mang
        sort(vt.begin(),vt.end());

        if(canPartitionKSubsets(vt,K)) cout << "1";
        else cout << "0";
        cout << endl;
        T--;
    }

    return 0;
}
