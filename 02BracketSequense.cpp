#include<bits/stdc++.h>

using namespace std;

// Kiem tra ngoac mo va ngoac dong
// ngoac mo ( "(","[" ) -> true
// ngoac dong -> false
bool checkNgoac(char c){
    if(c == '(' || c == '[')
        return true;
    else return false;
}

// Kiem tra cung bo
// vi du : "(" va ")" la cung mot bo -> tra ve true
// khac bo thi tra ve false
bool checkBo(char c1, char c2){
    if(c1 == '(' && c2 == ')')
        return true;
    if(c1 =='[' && c2 == ']')
        return true;
    return false;
}

// Kiem tra ngoac dung
bool checkBracket(string str){

}
int main(){
    string str;
    cin >> str;

    return 0;
}
