#include <iostream>

using namespace std;

int main()
{
    unsigned long long T;
    cin >> T;
    while(T>0){
        unsigned long long a,b,a1,b1,a2,b2;
        cin >> a >> b;
        a1 = a / 10;
        b1 = b / 10;
        a2 = a % 10;
        b2 = b % 10;

        if(a1+b1 == 0){
            cout << a2 + b2;
        } else {
            if(a2+b2 < 10){
                cout << a1 + b1 << a2 + b2;
            } else {
                cout << a1 + b1 + 1 << (a2+b2)%10;
            }
        }
        cout << endl;
        T--;
    }

    return 0;
}
