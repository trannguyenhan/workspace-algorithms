#include <iostream>
#include<string>
#include<vector>

using namespace std;

/*In ra so nhi phan tu ngan xep*/
void printBinaryFromVector(vector<int> a){
    while(!a.empty()){
        cout << a.back();
        a.pop_back();
    }
    return;
}

/*Thuc hien chia lien tiep cho 2 va luu ket qua vao ngan xep*/
vector<int> divBy2(int a){
    vector<int> vec;
    while(a>0){
        int c = a % 2;
        a = a / 2;
        vec.push_back(c);
    }
    return vec;
}

/*Thuc hien chuyen so thap phan sang so thap phan*/
void convertDecToBin(int a){
    vector<int> vec;
    vec = divBy2(a);
    printBinaryFromVector(vec);
}

/*In ra cac so nhi phan tu 1 den n*/
void convertBinFrom1ToN(int n){
    for(int i=1; i<=n; i++){
        convertDecToBin(i);
        cout << " ";
    }
    return;
}

int main()
{
    int T;
    cin >> T;
    
    while(T>0){
    	int n;
    	cin >> n;
    	convertBinFrom1ToN(n);
    	
    	T--;
    }
    
    return 0;
}
