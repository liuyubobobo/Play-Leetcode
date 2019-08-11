/// Source : https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together/
/// Author : liuyubobobo
/// Time   : 2019-08-10

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


/// Presum
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int minSwaps(vector<int>& data) {

        int n = data.size();
        int ones = accumulate(data.begin(), data.end(), 0);

        vector<int> presum(n + 1, 0);
        for(int i = 0; i < n; i ++)
            presum[i + 1] = presum[i] + data[i];

        int res = INT_MAX;
        for(int i = 0; i + ones <= n; i ++)
            res = min(res, ones - (presum[i + ones] - presum[i]));
        return res;
    }
};


int main() {

    return 0;
}