/// Source : https://leetcode.com/problems/longest-subsequence-with-limited-sum/
/// Author : liuyubobobo
/// Time   : 2022-08-27

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/// Greedy
/// Time Complexity: O(nlogn + qn)
/// Space Complexity: O(1)
class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {

        sort(nums.begin(), nums.end());

        vector<int> res(queries.size());
        for(int i = 0; i < queries.size(); i ++){
            int q = queries[i];

            int cur = 0, j;
            for(j = 0; j < nums.size() && cur <= q; j ++)
                cur += nums[j];
            res[i] = j - (cur > q);
        }
        return res;
    }
};


int main() {

    return 0;
}
