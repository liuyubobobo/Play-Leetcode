/// Source : https://leetcode.com/problems/minimum-recolors-to-get-k-consecutive-black-blocks/
/// Author : liuyubobobo
/// Time   : 2022-08-20

#include <iostream>
#include <vector>
#include <climits>

using namespace std;


/// Presum
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int minimumRecolors(string blocks, int k) {

        int n = blocks.size();
        vector<int> presum(n + 1, 0);
        for(int i = 0; i < n; i ++) presum[i + 1] = presum[i] + (blocks[i] == 'B');

        int res = INT_MAX;
        for(int start = 0; start + k <= n; start ++){
            int b = presum[start + k] - presum[start];
            res = min(res, k - b);
        }
        return res;
    }
};


int main() {

    return 0;
}
