/// Source : https://leetcode.com/problems/non-decreasing-subsequences/description/
/// Author : liuyubobobo
/// Time   : 2023-01-19

#include <iostream>
#include <vector>
#include <set>

using namespace std;


/// Backtrack
/// Time Compelxity: O(2^n)
/// Space Compelxity: O(n)
class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {

        int n = nums.size();
        set<vector<int>> res;
        vector<int> cur;
        dfs(n, nums, 0, cur, res);
        return vector<vector<int>>(res.begin(), res.end());
    }

private:
    void dfs(int n, const vector<int>& nums, int start,
             vector<int>& cur, set<vector<int>>& res){

        if(start == n){
            if(cur.size() >= 2) res.insert(cur);
            return;
        }

        dfs(n, nums, start + 1, cur, res);

        if(cur.empty() || nums[start] >= cur.back()){
            cur.push_back(nums[start]);
            dfs(n, nums, start + 1, cur, res);
            cur.pop_back();
        }
    }
};


int main() {

    return 0;
}
