/// Source : https://leetcode.com/problems/frog-jump/
/// Author : liuyubobobo
/// Time   : 2021-04-28

#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;


/// Memory Search
/// Time Complexity: O(n^2)
/// Space Complexity: O(n^2)
class Solution {
public:
    bool canCross(vector<int>& stones) {

        set<int> stones_set;
        for(int stone: stones) stones_set.insert(stone);

        if(!stones_set.count(0)) return false;
        if(!stones_set.count(1)) return false;

        map<pair<int, int>, bool> dp; // {pos, steps}
        return dfs(stones_set, 1, 1, stones.back(), dp);
    }

private:
    bool dfs(const set<int>& stones_set, int pos, int step, int end,
             map<pair<int, int>, bool>& dp){

        if(pos > end) return false;
        if(pos == end) return true;
        if(!stones_set.count(pos)) return false;

        if(dp.count({pos, step})) return dp[{pos, step}];

        bool res = dfs(stones_set, pos + step + 1, step + 1, end, dp);
        if(res) return dp[{pos, step}] = true;

        res = dfs(stones_set, pos + step, step, end, dp);
        if(res) return dp[{pos, step}] = true;

        if(step - 1 > 0)
            res = dfs(stones_set, pos + (step - 1), step - 1, end, dp);
        return dp[{pos, step}] = res;
    }
};


int main() {

    vector<int> stones1 = {0, 1, 3, 5, 6, 8, 12, 17};
    cout << Solution().canCross(stones1) << endl;
    // true

    vector<int> stones2 = {0, 1, 2, 3, 4, 8, 9, 11};
    cout << Solution().canCross(stones2) << endl;
    // false;

    return 0;
}
