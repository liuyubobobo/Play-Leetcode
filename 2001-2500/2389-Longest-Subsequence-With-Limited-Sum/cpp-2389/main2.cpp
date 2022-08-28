/// Source : https://leetcode.com/problems/longest-subsequence-with-limited-sum/
/// Author : liuyubobobo
/// Time   : 2022-08-27

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/// Greedy + Binary Search
/// Time Complexity: O(nlogn + qlogn)
/// Space Complexity: O(n)
class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {

        sort(nums.begin(), nums.end());

        vector<int> presum(nums.size() + 1, 0);
        for(int i = 0; i < nums.size(); i ++) presum[i + 1] = presum[i] + nums[i];

        vector<int> res(queries.size());
        for(int i = 0; i < queries.size(); i ++){
            int q = queries[i];

            if(q >= presum.back()){
                res[i] = nums.size();
                continue;
            }

            auto iter = upper_bound(presum.begin(), presum.end(), q);
            iter --;
            res[i] = iter - presum.begin();
        }
        return res;
    }
};


int main() {

    return 0;
}
