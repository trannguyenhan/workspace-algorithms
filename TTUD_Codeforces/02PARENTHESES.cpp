#include<bits/stdc++.h>
using namespace std;

// Kiem tra ngoac mo va ngoac dong
// ngoac mo ( "(","{","[" ) -> true
// ngoac dong -> false
bool checkNgoac(char c){
    if(c == '(' || c == '{' || c == '[')
        return true;
    else return false;
}

// Kiem tra cung bo
// vi du : "(" va ")" la cung mot bo -> tra ve true
// khac bo thi tra ve false
bool checkBo(char c1, char c2){
    if(c1 == '(' && c2 == ')')
        return true;
    if(c1 == '{' && c2 == '}')
        return true;
    if(c1 =='[' && c2 == ']')
        return true;
    return false;
}

// Xu ly tung bo test
void handling(string str){
    stack<char> st;
    int lens = str.length();

    for(int i=0; i<lens; i++){
        if(st.empty()){
            // Neu stack dang rong, ma lai them vao 1 ngoac dong -> false
            if(!checkNgoac(str[i])){
                cout << "0" << endl;
                return;
            } else {
                st.push(str[i]);
                continue;
            }
        } else {
            char temp1 = st.top();
            char temp2 = str[i];
            // Neu dinh stack va phan tu them vao la 1 bo thi lay phan tu o dinh ngan xep ra va xet tiep
            if(checkBo(temp1,temp2)){
                st.pop();
                continue;
            } else {
                if(checkNgoac(temp2)){
                    st.push(str[i]);
                    continue;
                } else {
                    cout << "0" << endl;
                    return;
                }
            }
        }
    }

    if(st.empty()) cout << "1" << endl;
    else cout << "0" << endl;

}

int main(){
    int n;
    string str;

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> str;
        handling(str);
    }

    return 0;
}
