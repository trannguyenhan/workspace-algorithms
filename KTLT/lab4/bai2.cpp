#include <iostream>
#include <cmath>
#include <iomanip>
#include <utility>
using namespace std;
using Point = pair<double, double>;

double distance(Point a, Point b){
    return sqrt((a.first - b.first)*(a.first - b.first) + (a.second - b.second)*(a.second - b.second));
}

double area(Point a, Point b, Point c) {
    /****************
        Ho va ten : Nguyen Quang Huy
        MSSV: 20183554
    */
    double ab = distance(a,b);
    double bc = distance(b,c);
    double ca = distance(c,a);

    double p = (ab + bc + ca) /2;
    return sqrt(p * (p-ab) * (p-bc) * (p-ca));
    /*****************/
}

int main() {
    printf("Ho Va Ten: Nguyen Quang Huy\n");
    printf("MSSV: 20183554\n\n");
    cout << setprecision(2) << fixed;
    cout << area({1, 2}, {2.5, 10}, {15, -5.25}) << endl;
    return 0;
}
