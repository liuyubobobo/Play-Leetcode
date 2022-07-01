/// Source : https://leetcode.com/problems/different-ways-to-add-parentheses/
/// Author : liuyubobobo
/// Time   : 2022-06-30

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O(n!)
/// Space Complexity: O(n)
class Solution {
public:
    vector<int> diffWaysToCompute(string exp) {

        vector<int> nums;
        vector<char> ops;
        for(int start = 0, i = 1; i <= exp.size(); i ++)
            if(i == exp.size() || !isdigit(exp[i])){
                nums.push_back(atoi(exp.substr(start, i - start).c_str()));

                if(i < exp.size()) ops.push_back(exp[i]);

                start = i + 1;
                i = start;
            }

//        for(int e: nums) cout << e << ' '; cout << '\n';
//        for(char op: ops) cout << op << ' '; cout << '\n';

        vector<int> res = dfs(nums, ops, 0, nums.size() - 1);
        return res;
    }

private:
    vector<int> dfs(const vector<int>& nums, const vector<char>& ops, int l, int r){

        if(l == r) return {nums[l]};

        vector<int> res;
        for(int left_end = l; left_end < r; left_end ++){
            vector<int> a = dfs(nums, ops, l, left_end);
            vector<int> b = dfs(nums, ops, left_end + 1, r);

            for(int e1: a)
                for(int e2: b)
                    res.push_back(calc(e1, e2, ops[left_end]));
        }
        return res;
    }

    int calc(int a, int b, char op){
        if(op == '+') return a + b;
        if(op == '-') return a - b;
        if(op == '*') return a * b;

        assert(false);
        return -1;
    }
};


void print_vec(const vector<int>& v){
    for(int e: v) cout << e << ' '; cout << '\n';
}

int main() {

    print_vec(Solution().diffWaysToCompute("2-1-1"));

    print_vec(Solution().diffWaysToCompute("2*3-4*5"));

    return 0;
}
