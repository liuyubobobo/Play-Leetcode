/// Source : https://leetcode.com/problems/check-if-all-the-integers-in-a-range-are-covered/
/// Author : liuyubobobo
/// Time   : 2021-06-12

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O(n * range)
/// Space Complexity: O(range)
class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {

        vector<bool> visited(right + 1, false);
        for(const vector<int>& r: ranges){
            for(int i = max(left, r[0]); i <= min(right, r[1]); i ++)
                visited[i] = true;
        }

        for(int i = left; i <= right; i ++)
            if(!visited[i]) return false;
        return true;
    }
};


int main() {

    vector<vector<int>> ranges1 = {{13,43},{19,20},{32,38},{26,33},{3,38},{16,31},{26,48},{27,43},{12,24}};
    cout << Solution().isCovered(ranges1, 36, 45) << endl;
    // true

    return 0;
}
