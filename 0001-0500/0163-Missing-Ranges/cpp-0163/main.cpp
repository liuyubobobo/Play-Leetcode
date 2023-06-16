/// Source : https://leetcode.com/problems/missing-ranges/
/// Author : liuyubobobo
/// Time   : 2020-12-08
/// Updated: 2022-06-16

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    vector<vector<int>> findMissingRanges(vector<int>& nums, int lower, int upper) {

        nums.push_back(upper + 1);

        vector<vector<int>> res;
        int l = lower;
        for(int i = 0; i < nums.size(); i ++){
            if(nums[i] == l) l ++;
            else{
                res.push_back({l, nums[i] - 1});
                l = nums[i] + 1;
            }
        }
        return res;
    }
};


void print_vec(const vector<vector<int>>& v){
    for(const vector<int>& seg: v) cout << '(' << seg[0] << ',' << seg[1] << ')';
    cout << '\n';
}

int main() {

    vector<int> nums1 = {0, 1, 3, 50, 75};
    print_vec(Solution().findMissingRanges(nums1, 0, 99));

    return 0;
}
