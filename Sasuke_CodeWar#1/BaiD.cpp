#include <iostream>
#include<vector>
#include<algorithm>
#include<fstream>
#include<math.h>
#include<sstream>

using namespace std;


vector<int> foulInFootball(vector<int> a){
    vector<int> b(12,0);
    vector<int> c;
    for(int i=0; i<a.size(); i++){
        int vitri = a[i];
        b[vitri]++;
        if(b[vitri] == 3){
            c.push_back(vitri);
            b[vitri] = 0;
        }
    }

    return c;
}

int main()
{

    return 0;
}
