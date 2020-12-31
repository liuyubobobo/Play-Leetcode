/// Source : https://leetcode.com/problems/combination-sum-iii/description/
/// Author : liuyubobobo
/// Time   : 2018-03-04

#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {

        vector<vector<int>> res;
        vector<int> cur_res;
        solve(1, k, n, cur_res, res);
        return res;
    }

private:
    void solve(int index, int k, int n,
               vector<int>& cur_res, vector<vector<int>>& res){

        if(n == 0 && k == 0){
            res.push_back(cur_res);
            return;
        }

        if(k == 0)
            return;

        for(int i = index ; i <= 9 ; i ++)
            if(n >= i){
                cur_res.push_back(i);
                solve(i + 1, k - 1, n - i, cur_res, res);
                cur_res.pop_back();
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

    vector<vector<int>> res1 = Solution().combinationSum3(3, 7);
    for(const vector<int>& a_res: res1)
        print_vec(a_res);

    cout << endl;

    vector<vector<int>> res2 = Solution().combinationSum3(3, 9);
    for(const vector<int>& a_res: res2)
        print_vec(a_res);

    return 0;
}