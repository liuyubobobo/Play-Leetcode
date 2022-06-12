/// Source : https://leetcode.com/problems/height-checker/s
/// Author : liuyubobobo
/// Time   : 2022-06-12

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/// Sorting
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    int heightChecker(vector<int>& heights) {

        vector<int> final(heights.begin(), heights.end());
        sort(final.begin(), final.end());

        int res = 0;
        for(int i = 0; i < heights.size(); i ++)
            res += heights[i] != final[i];
        return res;
    }
};


int main() {

    return 0;
}
