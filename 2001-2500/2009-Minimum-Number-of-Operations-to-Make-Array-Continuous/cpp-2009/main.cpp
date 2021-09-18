/// Source : https://leetcode.com/problems/minimum-number-of-operations-to-make-array-continuous/
/// Author : liuyubobobo
/// Time   : 2021-09-18

#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;


/// Greedy + Binary Search
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    int minOperations(vector<int>& nums) {

        set<int> unique_nums;
        for(int e: nums) unique_nums.insert(e);
        vector<int> data(unique_nums.begin(), unique_nums.end());

        int n = data.size();

        int res = (int)nums.size();
        for(int i = 0; i < n; i ++){
            vector<int>::iterator iter1 = lower_bound(data.begin(), data.end(), data[i] + nums.size());
            int k = (iter1 - data.begin()) - i;
            res = min(res, (int)nums.size()- k);
        }
        return res;
    }
};


int main() {

    vector<int> nums1 = {8, 5, 9, 9, 8, 4};
    cout << Solution().minOperations(nums1) << endl;
    // 2

    vector<int> nums2 = {8,10,16,18,10,10,16,13,13,16};
    cout << Solution().minOperations(nums2) << endl;
    // 6

    return 0;
}
