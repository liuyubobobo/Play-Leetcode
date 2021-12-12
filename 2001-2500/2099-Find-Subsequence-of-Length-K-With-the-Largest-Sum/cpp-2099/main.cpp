/// Source : https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/
/// Author : liuyubobobo
/// Time   : 2021-12-11

#include <iostream>
#include <vector>

using namespace std;


/// Sorting
/// Time Complexity: O(nlogn + klogk)
/// Space Complexity: O(n)
class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {

        vector<pair<int, int>> data(nums.size());
        for(int i = 0; i < nums.size(); i ++) data[i] = {nums[i], i};

        sort(data.begin(), data.end(), greater<pair<int, int>>());
        while(data.size() > k) data.pop_back();

        sort(data.begin(), data.end(),
             [](const pair<int, int>& p1, const pair<int, int>& p2){
            return p1.second < p2.second;
        });

        vector<int> res(k);
        for(int i = 0; i < k; i ++)
            res[i] = data[i].first;
        return res;
    }
};


int main() {

    return 0;
}
