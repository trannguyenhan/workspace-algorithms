#include <bits/stdc++.h>
using namespace std;

const int MAX = 800000;

int N;
string S;
int A[MAX]; // number of switch hand in substring from 0 to i
int D[MAX]; // number of switch hand in all substring from 0 to i
int status; // status = 0 => is use left hand, status = 1 => is use right hand

int result = 0;

void init(){
    cin >> N;
    cin >> S;
}

// true: need switch hand
// false: not switch hand
bool checkSwitchHand(int location, int lower_bound){
    if(S[location] == 'F') return false; // F not switch hand

    for(int i=location-1; i>=lower_bound; i--){
        if(S[i] != 'F'){
            if(S[i] == 'X'){
                if(S[location] == 'X') return false;
                else return true;
            } else { // S[i] == 'O'
                if(S[location] == 'O') return false;
                else return true;
            }
        }
    }

    return false;
}

// calculator start hand use
int calcStatus(string S){
    for(int i=0; i<MAX; i++){
        if(S[i] != 'F'){
            if(S[i] == 'X'){
                return 0; // use left hand
            } else if(S[i] == 'O'){
                return 1; // use right hand
            }
        }
    }

    return -1; // input text fail!
}

void solve(){
    A[0] = 0; // single text not need switch hand
    D[0] = 0;
    status = calcStatus(S);

    for(int i=1; i<N; i++){
        int location = i;

        int sum = 0;
        for(int j=0; j<i; j++){
            int lower_bound = j;

            if(checkSwitchHand(location, lower_bound)){
                sum += A[location-1] - A[j] + 1;
            } else {
                sum += A[location-1] - A[j];
            }
        }

        if(checkSwitchHand(location, 0)){
            A[i] = A[i-1] + 1;
        } else {
            A[i] = A[i-1];
        }

        D[i] = D[i-1] + sum;
        cout << "D[" << i << "] : " << D[i] << endl;
        cout << "A[" << i << "] : " << A[i] << endl;
    }

    result = D[N-1];
}

int main(){
    init();
    solve();

    cout << result << endl;
    return 0;
}