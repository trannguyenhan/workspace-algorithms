#include <iostream>
#include<vector>

using namespace std;

// Ham in tap con lien ke phia truoc
vector<int> tapConLienKePhiaTruoc(vector<int> tapcon, int N, int K){
    int i = tapcon.size() - 1;

    // neu tap con la cau hinh dau tien -> dua ve cau hinh cuoi cung
    if(tapcon[i] == K){
        for(int j=0; j<=i; j++){
            tapcon[j] = tapcon[j] + N-K;
        }
        return tapcon;
    }

    // Neu tap con la nhung cau hinh khac
    while(i >=0){

    }
}

// In ket qua ra man hin
void printResult(vector<int> vec){
    int dodai = vec.size();
    for(int i=0; i<dodai; i++){
        cout << vec[i] << " ";
    }
    return;
}

int main()
{
    int N, K;
    vector<int> tapcon;
    cin >> N >> K;

    for(int i=0; i<K; i++){
        int temp;
        cin >> temp;
        tapcon.push_back(temp);
    }

    tapcon = tapConLienKePhiaTruoc(tapcon);
    printResult(tapcon);
    return 0;
}
