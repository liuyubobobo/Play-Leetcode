/// Source : https://leetcode.com/problems/combination-sum-ii/description/
/// Author : liuyubobobo
/// Time   : 2018-03-04

#include <iostream>
#include <vector>

using namespace std;


/// Backtrack
/// Time Complexity: O(n^n)
/// Space Complexity: O(target)
class Solution {

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());

        vector<vector<int>> res;
        vector<int> cur_res;
        solve(candidates, 0, target, cur_res, res);
        return res;
    }

private:
    void solve(const vector<int> &candidates, int index, int target,
               vector<int>& cur_res, vector<vector<int>>& res){

        if(target == 0){
            res.push_back(cur_res);
            return;
        }

        for(int i = index ; i < candidates.size() ; i ++){
            if(i > index && candidates[i] == candidates[i-1])
                continue;
            if(target >= candidates[i]){
                cur_res.push_back(candidates[i]);
                solve(candidates, i + 1, target - candidates[i], cur_res, res);
                cur_res.pop_back();
            }
        }

        return;
    }
};


void print_vec(const vector<int>& vec){
    for(int e: vec)
        cout << e << " ";
    cout << endl;
}

int main() {

    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    vector<vector<int>> res = Solution().combinationSum2(candidates, 8);
    for(const vector<int>& a_res: res)
        print_vec(a_res);

    return 0;
}