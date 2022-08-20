/// Source : https://leetcode.com/problems/minimum-recolors-to-get-k-consecutive-black-blocks/
/// Author : liuyubobobo
/// Time   : 2022-08-20

#include <iostream>
#include <vector>
#include <climits>

using namespace std;


/// Sliding Window
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int minimumRecolors(string blocks, int k) {

        int n = blocks.size();
        int b = 0;
        for(int i = 0; i + 1 < k; i ++) b += blocks[i] == 'B';

        int res = INT_MAX;
        for(int i = k - 1; i < n; i ++){
            b += blocks[i] == 'B';
            res = min(res, k - b);
            b -= blocks[i - (k - 1)] == 'B';
        }
        return res;
    }
};


int main() {

    return 0;
}
