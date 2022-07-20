/// Source : https://leetcode.cn/contest/zj-future2022/problems/GVbKaI/
/// Author : liuyubobobo
/// Time   : 2022-07-19

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;


/// Presum
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int minSwaps(vector<int>& chess) {

        int n = chess.size();

        vector<int> presum(n + 1, 0);
        for(int i = 0; i < n; i ++) presum[i + 1] = presum[i] + chess[i];

        int res = INT_MAX, total = accumulate(chess.begin(), chess.end(), 0);
        for(int start = 0; start + total <= n; start ++)
            res = min(res, total - (presum[start + total] - presum[start]));
        return res;
    }
};


int main() {

    return 0;
}
