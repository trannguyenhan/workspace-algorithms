#include <iostream>
#include <map>
using namespace std;

template<class T>
map<T, double> fuzzy_set_union(const map<T, double> &a, const map<T, double> &b) {
    /****************
        Ho va ten : Nguyen Quang Huy
        MSSV : 20183554
    */
    map<T, double> c;
    for(auto v : a){
        int index = 0;
        for(auto u : b){
            if(v.first == u.first){
                c.insert({v.first, max(v.second, u.second)});
                index++;
                break;
            }
        }
        if(index == 0) c.insert({v.first, v.second});
    }

    for(auto v : b){
        int index = 0;
        for(auto u : a){
            if(v.first == u.first){
                c.insert({v.first, max(v.second, u.second)});
                index++;
                break;
            }
        }
        if(index == 0) c.insert({v.first, v.second});
    }
    return c;
    /*****************/
}

template<class T>
map<T, double> fuzzy_set_intersection(const map<T, double> &a, const map<T, double> &b) {
    /*****************/
    map<T, double> c;

    for(auto v : a){
        for(auto u : b){
            if(v.first == u.first){
                c.insert({v.first, min(v.second, u.second)});
                break;
            }
        }
    }

    return c;
    /*****************/
}

template<class T>
void print_fuzzy_set(const std::map<T, double> &a) {
    cout << "{ ";
    for (const auto &x : a) {
        std::cout << "(" << x.first << ", " << x.second << ") ";
    }
    cout << "}";
    std::cout << std::endl;
}

int main() {
    printf("Ho Va Ten: Nguyen Quang Huy\n");
    printf("MSSV: 20183554\n\n");
    std::map<int, double> a = {{1, 0.2}, {2, 0.5}, {3, 1}, {4, 0.6}, {5, 0.7}};
    std::map<int, double> b = {{1, 0.5}, {2, 0.4}, {4, 0.9}, {5, 0.4}, {6, 1}};
    std::cout << "A = "; print_fuzzy_set(a);
    std::cout << "B = "; print_fuzzy_set(b);
    std::map<int, double> c = fuzzy_set_union(a, b);
    std::map<int, double> d = fuzzy_set_intersection(a, b);
    std::cout << "Union: "; print_fuzzy_set(c);
    std::cout << "Intersection: "; print_fuzzy_set(d);
}
