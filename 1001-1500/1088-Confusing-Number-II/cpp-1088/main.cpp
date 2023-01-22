/// Source : https://leetcode.com/problems/confusing-number-ii/description/
/// Author : liuyubobobo
/// Time   : 2023-01-21

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/// Backtrack
/// Time Complexity: O(5^9)
/// Space Complexity: O(1)
class Solution {

private:
    const vector<int> valid_digits = {0, 1, 6, 8, 9};
    const vector<int> r_digits = {0, 1, -1, -1, -1, -1, 9, -1, 8, 6};

public:
    int confusingNumberII(int n) {

        int len = to_string(n).size();
        vector<int> nums(len);
        return dfs(len, nums, 0, 0, n);
    }

private:
    int dfs(int len, vector<int>& nums, int index, long long cur, long long n){

        if(cur > n) return 0;

        if(index == len){

            int i = 0;
            for(i = 0; i < len && nums[i] == 0; i ++);

            long long r = 0;
            for(int j = len - 1; j >= i; j --)
                r = r * 10ll + r_digits[nums[j]];
//            if(cur != r) cout << cur << '\n';
            return cur != r;
        }

        int res = 0;
        for(int d: valid_digits){
            nums[index] = d;
            res += dfs(len, nums, index + 1, cur * 10ll + d, n);
        }
        return res;
    }
};


int main() {

    cout << Solution().confusingNumberII(20) << '\n';
    // 6

    cout << Solution().confusingNumberII(100) << '\n';
    // 19

    cout << Solution().confusingNumberII(1000000000) << '\n';
    // 1950627

    return 0;
}
