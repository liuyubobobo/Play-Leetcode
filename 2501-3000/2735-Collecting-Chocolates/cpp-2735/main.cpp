/// Source : https://leetcode.com/problems/collecting-chocolates/description/
/// Author : liuyubobobo
/// Time   : 2023-06-19

#include <iostream>
#include <vector>
#include <climits>

using namespace std;


/// Brute Force
/// Time Complexity: O(n^2)
/// Space Complexity: O(n^2)
class Solution {
public:
    long long minCost(vector<int>& nums, int x) {

        int n = nums.size();

        vector<vector<long long>> min_table(n, vector<long long>(n, LONG_LONG_MAX));
        for(int start = 0; start < n; start ++){
            min_table[start][start] = nums[start];
            for(int i= start + 1; i < n; i ++)
                min_table[start][i] = min(min_table[start][i - 1], 0ll + nums[i]);
        }

        long long res = LONG_LONG_MAX;
        for(int offset = 0; offset < n; offset ++){
            res = min(res, solve(n, x, offset, min_table));
        }
        return res;
    }

private:
    long long solve(int n, long long x, int offset,
                    const vector<vector<long long>>& min_table){

        long long res = x * offset;
        for(int start = 0; start < n; start ++){
            int end = (start + offset) % n;

            if(start <= end) res += min_table[start][end];
            else res += min(min_table[start][n - 1], min_table[0][end]);
        }
        return res;
    }
};


int main() {

    return 0;
}
