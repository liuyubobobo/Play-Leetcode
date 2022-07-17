/// Source : https://leetcode.com/problems/query-kth-smallest-trimmed-number/
/// Author : liuyubobobo
/// Time   : 2022-07-16

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O(q * nlogn * len)
/// Space Complexity: O(n)
class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {

        int n = nums.size(), len = nums[0].size();

        vector<int> res(queries.size());
        for(int i = 0; i < queries.size(); i ++){
            res[i] = solve(n, len, nums, queries[i][0] - 1, queries[i][1]);
        }
        return res;
    }

private:
    int solve(int n, int len, const vector<string>& nums, int k, int x){

        vector<pair<string, int>> data(n);
        for(int i = 0; i < n; i ++)
            data[i] = {nums[i].substr(len - x), i};
        sort(data.begin(), data.end());
        return data[k].second;
    }
};


int main() {

    return 0;
}
