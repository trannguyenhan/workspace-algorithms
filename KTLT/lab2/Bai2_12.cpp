#include<bits/stdc++.h>
using namespace std;

struct element {
    int key;
    int value;
};

vector<element> lst;
void input(){
    int tmp1, tmp2;
    while(cin >> tmp1 && cin >> tmp2){
        element tmp;
        tmp.key = tmp1;
        tmp.value = tmp2;

        lst.push_back(tmp);
    }
}

void print(){
    for(int i=0; i<lst.size(); i++){
        cout << lst[i].key << " " << lst[i].value << endl;
    }
}

int main(){
    input();
    sort(lst.begin(),lst.end(),[] (element a, element b){
        if(a.value > b.value) return true;
        else if (a.value < b.value) return false;
        else {
            return a.key >= b.key;
        }
    });
    print();
}
