/// Source : https://leetcode.com/problems/3sum/
/// Author : liuyubobobo
/// Time   : 2016-12-03

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/// Using Hash Table to store all the numbers
///
/// Time Complexity: O(n^2)
/// Space Complexity: O(n)
class Solution {

public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        unordered_map<int, int> counter;
        for(int i = 0 ; i < nums.size() ; i ++)
            counter[nums[i]] ++;

        vector<vector<int>> res;

        if(counter[0] >= 3)
            res.push_back({0, 0, 0});

        // Remove duplication
        sort(nums.begin(), nums.end());
        vector<int>::iterator iter = unique(nums.begin(), nums.end());
        nums.erase(iter, nums.end());

        for(int i = 0 ; i < nums.size() ; i ++)
            for(int j = i + 1 ; j < nums.size() ; j ++){

                if(nums[i] * 2 + nums[j] == 0 && counter[nums[i]] >= 2)
                    res.push_back({nums[i], nums[i], nums[j]});

                if(nums[i] + nums[j] * 2 == 0 && counter[nums[j]] >= 2)
                    res.push_back({nums[i], nums[j], nums[j]});

                int c = 0 - nums[i] - nums[j];
                if(c > nums[j] && counter[c] != 0)
                    res.push_back({nums[i], nums[j], c});
            }

        return res;
    }
};

int main() {

    vector<int> nums1 = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> res = Solution().threeSum(nums1);
    for( int i = 0 ; i < res.size() ; i ++ ){
        for( int j = 0 ; j < res[i].size() ; j ++ )
            cout<<res[i][j]<<" ";
        cout<<endl;
    }

    return 0;
}