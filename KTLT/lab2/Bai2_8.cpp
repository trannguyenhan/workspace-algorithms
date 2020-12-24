#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    printf("Ho Va Ten: Nguyen Quang Huy\n");
    printf("MSSV: 20183554\n\n");
    int val1, val2;
    cin >> val1 >> val2;
    vector< vector<int> > a = {
        {1, 3, 7},
        {2, 3, 4, val1},
        {9, 8, 15},
        {10, val2},
    };

    //# sắp xếp các vector trong a theo tổng các phần tử giảm dần
    /****************
        Ho va ten : Nguyen Quang Huy
        MSSV : 20183554
    */
    sort(a.begin(), a.end(), [](vector<int> x, vector<int> y){
            int sum1 = 0;
            for(unsigned int i=0; i<x.size(); i++)
                sum1 += x[i];

            int sum2 = 0;
            for(unsigned int i=0; i<y.size(); i++)
                sum2 += y[i];

            return sum1 > sum2;
         });
    /*****************/

    for (const auto &v : a) {
        for (int it : v) {
            cout << it << ' ';
        }
        cout << endl;
    }
    return 0;
}
