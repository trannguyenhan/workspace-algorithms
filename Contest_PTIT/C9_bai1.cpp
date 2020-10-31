#include <iostream>
#include<string>
#include<vector>
#include<queue>
#include<math.h>

using namespace std;


void printDSKe(vector<vector<int> > dscanh){
    for(int i=1; i<dscanh.size(); i++){
        cout << i << ": ";
        for(int j=0; j<dscanh[i].size(); j++){
            cout << dscanh[i].at(j) << " ";
        }
        cout << endl;
    }

    return;
}

int main()
{
    int T;
    cin >> T;

    while(T>0){
        int V, E;
        cin >> V >> E;
        vector<vector<int> > dscanh(V+1); // k lay dinh 0 -> bat dau dem tu dinh 1 len coi nhu bo dinh 0

        for(int i=0; i<E; i++){
            int temp1, temp2;
            cin >> temp1 >> temp2;

            dscanh[temp1].push_back(temp2); // Gan temp2 la dinh ke cua dinh temp1
            dscanh[temp2].push_back(temp1); // Gan temp1 la dinh ke cua dinh temp2
        }

        printDSKe(dscanh);
        T--;
    }

    return 0;
}
