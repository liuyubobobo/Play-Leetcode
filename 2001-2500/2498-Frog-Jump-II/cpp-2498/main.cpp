#include <iostream>
#include <vector>
#include <set>

using namespace std;


class Solution {
public:
    int maxJump(vector<int>& stones) {

        stones.push_back(stones.back());

        int n = stones.size(), res = 0;
        for(int i = 2; i < n; i += 2)
            res = max(res, stones[i] - stones[i - 2]);

        res = max(res, stones[1]);
        for(int i = 3; i < n; i += 2)
            res = max(res, stones[i] - stones[i - 2]);
        return res;
    }
};


int main() {

    vector<int> stones1 = {0, 3, 9};
    cout << Solution().maxJump(stones1) << '\n';
    // 9

    return 0;
}
