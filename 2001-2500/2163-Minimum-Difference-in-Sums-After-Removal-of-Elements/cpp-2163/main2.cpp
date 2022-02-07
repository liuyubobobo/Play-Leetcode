/// Source : https://leetcode.com/problems/minimum-difference-in-sums-after-removal-of-elements/
/// Author : liuyubobobo
/// Time   : 2022-02-06

#include <iostream>
#include <vector>
#include <queue>
#include <numeric>
#include <cassert>

using namespace std;


/// Premin + Sufmax, only using priority queues
/// Time Complexity: O(nlogn)
/// Space Compelxity: O(n)
class Solution {
public:
    long long minimumDifference(vector<int>& nums) {

        int n3 = nums.size(), n = n3 / 3, n2 = 2 * n;

        // premin
        vector<long long> premin(n3, 0);
        priority_queue<int> pq;
        long long sum = 0;
        for(int i = 0; i < n; i ++)
            pq.push(nums[i]), sum += nums[i];

        premin[n - 1] = sum;
        for(int i = n; i < n2; i ++){
            pq.push(nums[i]), sum += nums[i];
            int maxv = pq.top(); pq.pop(); sum -= maxv;
            premin[i] = sum;
        }

        // sufmax
        vector<long long> sufmax(n3, 0);
        priority_queue<int, vector<int>, greater<int>> pq2;
        sum = 0;
        for(int i = n3 - 1; i >= n2; i --)
            pq2.push(nums[i]), sum += nums[i];

        sufmax[n2] = sum;
        for(int i = n2 - 1; i >= n; i --){
            pq2.push(nums[i]), sum += nums[i];
            int minv = pq2.top(); pq2.pop(); sum -= minv;
            sufmax[i] = sum;
        }

        long long res = LONG_LONG_MAX;
        for(int i = n - 1; i < n2; i ++)
            res = min(res, premin[i] - sufmax[i + 1]);
        return res;
    }
};


int main() {

    vector<int> nums1 = {3, 1, 2};
    cout << Solution().minimumDifference(nums1) << endl;
    // -1

    vector<int> nums2 = {7, 9, 5, 8, 1, 3};
    cout << Solution().minimumDifference(nums2) << endl;
    // 1

    return 0;
}
