/// Source : https://leetcode.com/problems/subsets/
/// Author : liuyubobobo
/// Time   : 2021-07-24

#include <iostream>
#include <vector>

using namespace std;


/// Subsets traversal
/// Time Compelexity: O(2^n)
/// Space Complexity: O(2^n)
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> res;

        int n = nums.size();
        for(int state = 0; state < (1 << n); state ++)
            res.push_back(get_subsets(state, nums));
        return res;
    }

private:
    vector<int> get_subsets(int state, const vector<int>& nums){

        vector<int> res;
        int k = 0;
        while(state){
            if(state & 1) res.push_back(nums[k]);
            state >>= 1, k ++;
        }
        return res;
    }
};


int main() {

    return 0;
}
