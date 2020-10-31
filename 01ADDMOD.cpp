#include <iostream>

using namespace std;
const unsigned long long P = 1000000000 + 7;

int reValue(int n){
    int buffer = n / P;
    int result = n - buffer*P;
    return result;
}

int main()
{
    unsigned long long a, b;
    cin >> a >> b ;

    a = reValue(a);
    b = reValue(b);

    unsigned long long S = a + b;
    S = reValue(S);

    cout << S;
    return 0;
}
