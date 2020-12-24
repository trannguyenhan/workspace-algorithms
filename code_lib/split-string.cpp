// tach xau va chuyen sau thanh so
#include<bits/stdc++.h>
using namespace std;

int main(){
    string str = "12 15 18 17";
    vector<int> vt;
    while (!str.empty()){
        stringstream convert(str.substr(0, str.find(" ")));
        int tmp = 0;
        convert >> tmp;
        vt.push_back(tmp - 1);

        if (str.find(" ") > str.size()){
            break;
        } else {
            str.erase(0, str.find(" ") + 1); // Update string
        }
    }

    for(int i=0; i<vt.size(); i++)
        cout << vt[i] << " ";
}
