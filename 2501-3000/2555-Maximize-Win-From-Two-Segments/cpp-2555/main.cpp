/// Source : https://leetcode.com/problems/maximize-win-from-two-segments/description/
/// Author : liuyubobobo
/// Time   : 2023-02-04

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;


/// DP + Binary Search
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    int maximizeWin(vector<int>& pos, int k) {

        int n = pos.size();

        vector<int> dp(n + 1, 0);
        int res = 0;
        for(int i = n - 1; i >= 0; i --){
            auto iter = upper_bound(pos.begin() + i, pos.end(), pos[i] + k);
            int r = (iter - pos.begin());
            int tres = r - i;
            res = max(res, tres + dp[r]);
            dp[i] = max(tres, dp[i + 1]);
        }
        return res;
    }
};


int main() {


    return 0;
}
