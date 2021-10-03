/// Source : https://leetcode.com/problems/maximum-number-of-ways-to-partition-an-array/
/// Author : liuyubobobo
/// Time   : 2021-10-03

#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;


/// Presum + Using HashSet + Binary Search
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    int waysToPartition(vector<int>& nums, int k) {

        int n = nums.size();
        vector<long long> presum(n, nums[0]);
        for(int i = 1; i < n; i ++)
            presum[i] = presum[i - 1] + nums[i];

        int res = 0;
        for(int p = 0; p + 1 < n; p ++) {
            // [0...p] == [p + 1... n - 1]
            if (presum[p] == presum[n - 1] - presum[p])
                res ++;
        }

        map<long long, vector<int>> f;
        for(int i = 0; i + 1 < n; i ++)
            f[presum[i]].push_back(i);

        for(int i = 0; i < n; i ++){
            // try to change nums[i] to k
            long long delta = k - nums[i];
            if(delta == 0) continue;

            int tres = 0;

            if((presum[n - 1] - delta) % 2 == 0){
                vector<int>& v1 = f[(presum[n - 1] - delta) / 2];
                tres += v1.end() - lower_bound(v1.begin(), v1.end(), i);
            }

            if((presum[n - 1] + delta) % 2 == 0){
                vector<int>& v2 = f[(presum[n - 1] + delta) / 2];
                auto iter = lower_bound(v2.begin(), v2.end(), i);
                tres += iter - v2.begin();
            }

            res = max(res, tres);
        }

        return res;
    }
};

int main() {

    vector<int> nums0 = {0,0,100,0};
    cout << Solution().waysToPartition(nums0, 0) << endl;
    // 3

    vector<int> nums1 = {2, -1, 2};
    cout << Solution().waysToPartition(nums1, 3) << endl;
    // 1

    vector<int> nums2 = {0, 0, 0};
    cout << Solution().waysToPartition(nums2, 1) << endl;
    // 2

    vector<int> nums3 = {22,4,-25,-20,-15,15,-16,7,19,-10,0,-13,-14};
    cout << Solution().waysToPartition(nums3, -33) << endl;
    // 4

    vector<int> nums4 = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,30827,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    cout << Solution().waysToPartition(nums4, 0) << endl;
    // 33

    vector<int> nums5 = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,99,0,0,0,0,-99,0};
    cout << Solution().waysToPartition(nums5, 0) << endl;
    // 60

    vector<int> nums6 = {0,0,0,1077,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,70590,0,0,0,0,0,0,0,0,0,0,0,0,0};
    cout << Solution().waysToPartition(nums6, 1077) << endl;
    // 57

    return 0;
}
