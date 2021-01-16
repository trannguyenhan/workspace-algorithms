#include<bits/stdc++.h>
using namespace std;

const int INF = 1000000000;

struct Block {
    int x, y, z;

    Block() {}
    Block(int x, int y, int z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }
};

void solve(int test) {
    int n;
    cin >> n;
    if (n == 0) exit(0);

    vector<Block> blocks;
    blocks.push_back(Block(INF, INF, 0));

    for (int i = 0; i < n; i++) {
        vector<int> a(3);
        for (int &e : a) cin >> e;
        sort(a.begin(), a.end());
        do {
            blocks.push_back(Block(a[0], a[1], a[2]));
        } while (next_permutation(a.begin(), a.end()));
    }

    sort(blocks.begin(), blocks.end(), [&](Block &lhs, Block &rhs) {
        return lhs.x > rhs.x;
    });

    vector<int> dp(blocks.size(), 0);

    for (int i = 1; i < blocks.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (blocks[j].x > blocks[i].x && blocks[j].y > blocks[i].y) {
                dp[i] = max(dp[i], dp[j] + blocks[i].z);
            }
        }
    }

    cout << "Case " << test << ": maximum height = ";
    cout << *max_element(dp.begin(), dp.end()) << '\n';

}

int main() {
    int test = 0;
    while (true) {
        test++;
        solve(test);
    }
}

