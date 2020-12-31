/// Source : https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/
/// Author : liuyubobobo
/// Time   : 2020-11-15

#include <iostream>
#include <vector>
#include <numeric>
#include <unordered_map>

using namespace std;


/// Presum + HashMap
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {

        int n = nums.size();
        int t = accumulate(nums.begin(), nums.end(), 0) - x;

        unordered_map<int, int> map;
        map[0] = -1;
        int cur = 0, res = t == 0 ? n : INT_MAX;
        for(int i = 0; i < n; i ++){
            cur += nums[i];
            if(map.count(cur - t))
                res = min(res, n - (i - map[cur - t]));
            map[cur] = i;
        }
        return res == INT_MAX ? -1 : res;
    }
};


int main() {

    vector<int> nums1 = {1, 1, 4, 2, 3};
    cout << Solution().minOperations(nums1, 5) << endl;
    // 2

    vector<int> nums2 = {5, 6, 7, 8, 9};
    cout << Solution().minOperations(nums2, 4) << endl;
    // -1

    vector<int> nums3 = {3,2,20,1,1,3};
    cout << Solution().minOperations(nums3, 10) << endl;
    // 5

    vector<int> nums4 = {8828,9581,49,9818,9974,9869,9991,10000,10000,10000,9999,9993,9904,8819,1231,6309};
    cout << Solution().minOperations(nums4, 134365) << endl;
    // 16

    return 0;
}
