#include <iostream>
#include<vector>

using namespace std;
const int MAX = 1000000000+7;

int reValue(int val){
  while(val > MAX){
    val = val - MAX;
  }
  return val;
}

int main() {
 int n;
 vector<int> vt;
 int SUM = 0;

 cin >> n;

 for(int i=0; i<n; i++){
   int temp;
   cin >> temp;
   temp = reValue(temp);
   SUM = SUM + temp;
   SUM = reValue(SUM);
 }

 cout << SUM;

}
