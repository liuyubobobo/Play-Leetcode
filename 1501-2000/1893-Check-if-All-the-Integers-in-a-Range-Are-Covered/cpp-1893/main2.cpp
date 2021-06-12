/// Source : https://leetcode.com/problems/check-if-all-the-integers-in-a-range-are-covered/
/// Author : liuyubobobo
/// Time   : 2021-06-12

#include <iostream>
#include <vector>

using namespace std;


/// Sorting
/// Time Complexity: O(nlogn)
/// Space Complexity: O(1)
class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {

        sort(ranges.begin(), ranges.end());
        for(const vector<int>& r: ranges)
            if(r[0] > left) return false;
            else{
                left = max(left, r[1] + 1);
                if(left > right) return true;
            }
        return false;
    }
};


int main() {

    vector<vector<int>> ranges1 = {{13,43},{19,20},{32,38},{26,33},{3,38},{16,31},{26,48},{27,43},{12,24}};
    cout << Solution().isCovered(ranges1, 36, 45) << endl;
    // true

    return 0;
}
