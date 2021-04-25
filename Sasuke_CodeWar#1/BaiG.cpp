#include <iostream>
#include<vector>
#include<algorithm>
#include<fstream>
#include<math.h>
#include<sstream>

using namespace std;

bool possibleName(string name, string typed){
    int lensName = name.length();
    int lensTyped = typed.length();

    vector<int> a;
    int i=0, j=0;
    while(j<lensTyped){
        if(name[i] == typed[j]){
            a.push_back(name[i]);
            i++;
            j++;
        } else {
            if(a.empty()){ return false; }
            else {
                if(typed[j] == a.back()){
                    j++;
                } else { return false; }
            }
        }

    }

    return true;

}

int main()
{

    return 0;
}
