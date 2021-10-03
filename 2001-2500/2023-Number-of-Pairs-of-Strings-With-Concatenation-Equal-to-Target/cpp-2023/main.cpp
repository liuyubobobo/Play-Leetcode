/// Source : https://leetcode.com/problems/number-of-pairs-of-strings-with-concatenation-equal-to-target/
/// Author : liuyubobobo
/// Time   : 2021-10-02

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O(n^2 * |nums[i].length|)
/// Space Complexity: O(1)
class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {

        int res = 0, n = nums.size();
        for(int i = 0; i < n; i ++)
            for(int j = 0; j < n; j ++)
                if(i != j) res += nums[i] + nums[j] == target;
        return res;
    }
};


int main() {

    return 0;
}
