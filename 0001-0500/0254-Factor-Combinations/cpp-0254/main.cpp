/// Source : https://leetcode.com/problems/factor-combinations/description/
/// Author : liuyubobobo
/// Time   : 2018-03-04

#include <iostream>
#include <vector>

using namespace std;


/// Backtrack
/// Time Complexity: O(2^n)
/// Space Complexity: O(n)
class Solution {
public:
    vector<vector<int>> getFactors(int n) {

        vector<vector<int>> res;
        vector<int> cur_res;
        solve(2, n, n, cur_res, res);
        return res;
    }

private:
    void solve(int index, int n, int target,
               vector<int>& cur_res, vector<vector<int>>& res){

        if(n == 1){
            if(cur_res.size() != 0)
                res.push_back(cur_res);
            return;
        }

        for(int i = index ; i <= n ; i ++)
            if(i != target && n % i == 0){
                cur_res.push_back(i);
                solve(i, n / i, target, cur_res, res);
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

    vector<vector<int>> res1 = Solution().getFactors(1);
    for(const vector<int>& a_res: res1)
        print_vec(a_res);
    cout << endl;

    vector<vector<int>> res2 = Solution().getFactors(37);
    for(const vector<int>& a_res: res2)
        print_vec(a_res);
    cout << endl;

    vector<vector<int>> res3 = Solution().getFactors(12);
    for(const vector<int>& a_res: res3)
        print_vec(a_res);
    cout << endl;

    vector<vector<int>> res4 = Solution().getFactors(32);
    for(const vector<int>& a_res: res4)
        print_vec(a_res);
    cout << endl;

    return 0;
}