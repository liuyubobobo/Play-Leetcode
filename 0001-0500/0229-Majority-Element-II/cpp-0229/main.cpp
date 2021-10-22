/// Source : https://leetcode.com/problems/majority-element-ii/
/// Author : liuyubobobo
/// Time   : 2021-10-21

#include <iostream>
#include <vector>

using namespace std;


/// Sorting
/// Time Complexity: O(nlogn)
/// Space Complexity: O(1)
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        vector<int> res;

        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int start = 0, i = 1; i <= n; i ++)
            if(i == n || nums[i] != nums[start]){
                if(i - start > n / 3) res.push_back(nums[start]);
                start = i;
            }
        return res;
    }
};


int main() {

    return 0;
}
