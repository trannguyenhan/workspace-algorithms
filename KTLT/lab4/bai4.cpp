#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void print_vector(const vector<int> &a) {
    for (int v : a) cout << v << ' ';
    cout << endl;
}

bool compare(int a, int b){
    return a > b;
}

vector<int> delete_even(vector<int> &a) {
    /****************
        Ho va ten : Nguyen Quang Huy
        MSSV : 20183554
    */
    vector<int> tmp;
    for(int v : a){
        if(v % 2 != 0) tmp.push_back(v);
    }
    return tmp;
    /*****************/
}

void sort_decrease(vector<int> &a) {
    /****************
        Ho va ten : Nguyen Quang Huy
        MSSV : 20183554
    */
    sort(a.begin(), a.end(), compare);
    /*****************/
}

vector<int> merge_vectors(const vector<int> &a, const vector<int> &b) {
    /*****************/
    vector<int> sum;
    for(int v : a){
        sum.push_back(v);
    }

    for(int v : b){
        sum.push_back(v);
    }

    sort(sum.begin(), sum.end(), compare);
    return sum;
    /*****************/
}

int main() {
    printf("Ho Va Ten: Nguyen Quang Huy\n");
    printf("MSSV: 20183554\n\n");
    int m, n, u;
    std::vector<int> a, b;

    std::cin >> m >> n;
    for(int i = 0; i < m; i++){
        std:: cin >> u;
        a.push_back(u);
    }
    for(int i = 0; i < n; i++){
        std:: cin >> u;
        b.push_back(u);
    }

    a = delete_even(a);
    cout << "Odd elements of a: ";
    print_vector(a);

    b = delete_even(b);
    cout << "Odd elements of b: ";
    print_vector(b);

    sort_decrease(a);
    cout << "Decreasingly sorted a: ";
    print_vector(a);

    sort_decrease(b);
    cout << "Decreasingly sorted b: ";
    print_vector(b);

    vector<int> c = merge_vectors(a, b);
    cout << "Decreasingly sorted c: ";
    print_vector(c);

    return 0;
}
