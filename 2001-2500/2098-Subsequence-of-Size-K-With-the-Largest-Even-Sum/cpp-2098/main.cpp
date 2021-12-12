/// Source : https://leetcode.com/problems/subsequence-of-size-k-with-the-largest-even-sum/
/// Author : liuyubobobo
/// Time   : 2021-12-11

#include <iostream>
#include <vector>

using namespace std;


/// Sorting
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    long long largestEvenSum(vector<int>& nums, int k) {

        vector<int> odd, even;
        for(int e: nums)
            if(e % 2) odd.push_back(e);
            else even.push_back(e);

        sort(odd.begin(), odd.end(), greater<int>());
        sort(even.begin(), even.end(), greater<int>());

        vector<long long> odd_presum(odd.size() + 1, 0), even_presum(even.size() + 1, 0);
        for(int i = 0; i < odd.size(); i ++)
            odd_presum[i + 1] = odd_presum[i] + odd[i];
        for(int i = 0; i < even.size(); i ++)
            even_presum[i + 1] = even_presum[i] + even[i];

        long long res = -1;
        for(int odd_num = 0; odd_num <= odd.size(); odd_num += 2){
            int even_num = k - odd_num;
            if(even_num < 0 || even_num > even.size()) continue;

            res = max(res, odd_presum[odd_num] + even_presum[even_num]);
        }
        return res;
    }
};


int main() {

    vector<int> nums1 = {4, 1, 5, 3, 1};
    cout << Solution().largestEvenSum(nums1, 3) << endl;
    // 12

    vector<int> nums2 = {4, 6, 2};
    cout << Solution().largestEvenSum(nums2, 3) << endl;
    // 12

    vector<int> nums3 = {1, 3, 5};
    cout << Solution().largestEvenSum(nums3, 1) << endl;
    // -1

    return 0;
}
