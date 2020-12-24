#include<bits/stdc++.h>
using namespace std;
const int MAX = 100005;

int n, m; // n vertex, m edge
vector< vector<int> > vt;
vector<int> part1;
vector<int> part2;

void input(){
    cin >> n >> m;
    vt.resize(n+1);

    for(int i=0; i<m; i++){
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;

        vt[tmp1].push_back(tmp2);
        vt[tmp2].push_back(tmp1);
    }
}

bool solve(){
    set<int> no_put_part1;
    set<int> no_put_part2;
    int mark1 = 0;
    int mark2 = 0;

    for(int i=1; i<=n; i++){
        //cout << "check " << i << " : ";
        // check part1
        auto find_d = find(no_put_part1.begin(), no_put_part1.end(),i);
        if(find_d == no_put_part1.end()){
            set<int> tmp_part1(no_put_part1);
            for(int v : vt[i]){
                tmp_part1.insert(v);
            }

            mark1 = tmp_part1.size() + no_put_part2.size();
        }

        find_d = find(no_put_part2.begin(), no_put_part2.end(),i);
        if(find_d == no_put_part2.end()){
            set<int> tmp_part2(no_put_part2);
            for(int v : vt[i]){
                tmp_part2.insert(v);
            }

            mark2 = tmp_part2.size() + no_put_part1.size();
        }

        //cout << mark1 << " " << mark2 << endl;
        if(mark1 == 0 && mark2 == 0){
            return false;
        } else {
            if(mark1 == 0 && mark2 != 0){
                for(int v : vt[i]){
                    no_put_part1.insert(v);
                }
            } else if(mark1 != 0 && mark2 == 0){
                for(int v : vt[i]){
                    no_put_part2.insert(v);
                }
            } else {
                if(mark1 < mark2){
                    for(int v : vt[i]){
                        no_put_part1.insert(v);
                    }
                } else {
                    for(int v : vt[i]){
                        no_put_part2.insert(v);
                    }
                }
            }
        }

        mark1 = 0;
        mark2 = 0;
    }

    return true;
}

int main(){
    input();

    if(solve()) cout << "1";
    else cout << "0";
    return 0;
}
