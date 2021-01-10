/// Source : https://leetcode.com/problems/summary-ranges/
/// Author : liuyubobobo
/// Time   : 2021-01-10

#include <iostream>
#include <vector>

using namespace std;


/// Split
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {

        vector<string> res;
        for(int start = 0, i = 1; i <= nums.size(); i ++)
            if(i == nums.size() || nums[i] != nums[i - 1] + 1){
                if(i - start == 1) res.push_back(to_string(nums[start]));
                else res.push_back(to_string(nums[start]) + "->" + to_string(nums[i - 1]));

                start = i;
                i = start;
            }
        return res;
    }
};


int main() {

    return 0;
}
