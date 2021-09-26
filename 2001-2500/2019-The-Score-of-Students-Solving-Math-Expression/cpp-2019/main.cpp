/// Source : https://leetcode.com/problems/the-score-of-students-solving-math-expression/
/// Author : liuyubobobo
/// Time   : 2021-09-25

#include <iostream>
#include <vector>
#include <set>
#include <cassert>
#include <numeric>

using namespace std;


/// DP
/// Time Complexity: O(15^3 * 1000^2 + |answers|)
/// Space Complexity: O(15^3 * 1000)
class Solution {
public:
    int scoreOfStudents(string s, vector<int>& answers) {

        vector<int> nums = {s[0] - '0'};
        vector<char> ops;
        for(int i = 1; i < s.size(); i += 2){
            ops.push_back(s[i]);
            nums.push_back(s[i + 1] - '0');
        }

        int n = nums.size();
        vector<vector<set<int>>> dp(n, vector<set<int>>(n));
        for(int i = 0; i < n; i ++) dp[i][i].insert(nums[i]);
        for(int sz = 2; sz <= n; sz ++)
            for(int l = 0; l + sz <= n; l ++){
                // dp[l][l + sz - 1]
                for(int lsz = 1; lsz < sz; lsz ++){
                    for(int e1: dp[l][l + lsz - 1])
                        for(int e2: dp[l + lsz][l + sz - 1]){
                            if(ops[l + lsz - 1] == '+' && e1 + e2 <= 1000)
                                dp[l][l + sz - 1].insert(e1 + e2);
                            else if(ops[l + lsz - 1] == '*' && e1 * e2 <= 1000)
                                dp[l][l + sz - 1].insert(e1 * e2);
                        }
                }
            }

        int correct_ans = get_correct_ans(nums, ops);
        int res = 0;
        for(int ans: answers)
            if(ans == correct_ans) res += 5;
            else if(dp[0][n - 1].count(ans)) res += 2;
        return res;
    }

private:
    int get_correct_ans(const vector<int>& nums, const vector<char>& ops){

        vector<int> stack = {nums[0]};
        for(int i = 0; i < ops.size(); i ++) {
            if (ops[i] == '*') {
                int first = stack.back();
                stack.pop_back();
                stack.push_back(first * nums[i + 1]);
            } else stack.push_back(nums[i + 1]);
        }

        return accumulate(stack.begin(), stack.end(), 0);
    }
};


int main() {

    vector<int> ans1 = {20, 13, 42};
    cout << Solution().scoreOfStudents("7+3*1*2", ans1) << endl;
    // 7

    vector<int> ans2 = {13,0,10,13,13,16,16};
    cout << Solution().scoreOfStudents("3+5*2", ans2) << endl;
    // 19

    vector<int> ans3 = {12,9,6,4,8,6};
    cout << Solution().scoreOfStudents("6+0*1", ans3) << endl;
    // 10

    vector<int> ans4 = {12,9,6,4,8,6};
    cout << Solution().scoreOfStudents("9*9*3+6*6+3*3+6*6+6*3+9*9+6*3", ans4) << endl;

    return 0;
}
