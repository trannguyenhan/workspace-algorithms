#include <iostream>
using namespace std;

void output(string str){
  int lens = str.length();
  if(lens > 10){
    cout << str[0] << lens-2 << str[lens-1] << endl;
  } else {
    cout << str << endl;
  }

}

int main() {
  int T;
  cin >> T;

  while(T>0){
    string str;
    cin >> str;

    output(str);

    T--;

  }
}
