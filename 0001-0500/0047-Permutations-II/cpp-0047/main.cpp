/// Source : https://leetcode.com/problems/permutations-ii/description/
/// Author : liuyubobobo
/// Time   : 2017-12-18

#include <iostream>
#include <vector>

using namespace std;

/// Most Naive Recursive
/// Time Complexity: O(n^n)
/// Space Complexity: O(n)
class Solution {

private:
    vector<vector<int>> res;
    vector<bool> used;

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {

        res.clear();
        if(nums.size() == 0)
            return res;

        used = vector<bool>(nums.size(), false);
        sort(nums.begin(), nums.end());
        vector<int> p;

        generatePermutation(nums, 0, p);

        return res;
    }

private:
    void generatePermutation(const vector<int>& nums, int index, vector<int> &p){

        if(index == nums.size()){
            res.push_back(p);
            return;
        }

        for(int i = 0 ; i < nums.size() ; i ++)
            if(!used[i]){
                if(i > 0 && nums[i] == nums[i-1] && !used[i-1])
                    continue;
                p.push_back(nums[i]);
                used[i] = true;

                generatePermutation(nums, index + 1, p);

                p.pop_back();
                used[i] = false;
            }

    }
};


void printVec(const vector<int>& vec){
    for(int e: vec)
        cout << e << " ";
    cout << endl;
}

int main() {

    vector<int> nums1 = {1, 1, 2};
    vector<vector<int>> res1 = Solution().permuteUnique(nums1);
    for(const vector<int>& tres: res1)
        printVec(tres);

    vector<int> nums2 = {2, 2, 1, 1};
    vector<vector<int>> res2 = Solution().permuteUnique(nums2);
    for(const vector<int>& tres: res2)
        printVec(tres);

    return 0;
}