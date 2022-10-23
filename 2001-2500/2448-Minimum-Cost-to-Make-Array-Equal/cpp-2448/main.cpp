/// Source : https://leetcode.com/problems/minimum-cost-to-make-array-equal/
/// Author : liuyubobobo
/// Time   : 2022-10-22

#include <iostream>
#include <vector>

using namespace std;


/// Ad-Hoc
/// Time Complexity: O(nlogn + max_nums)
/// Space Complexity: O(n)
class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {

        int n = nums.size();

        long long cur_cost = 0;
        for(int i = 0; i < n; i ++) cur_cost += 1ll * nums[i] * cost[i];
        long long res_cost = cur_cost;

        vector<pair<int, int>> data(n);
        for(int i = 0; i < n; i ++) data[i] = {nums[i], cost[i]};
        sort(data.begin(), data.end());
        int index = 0;

        long long above_cost_d = 0;
        for(int i = 0; i < n; i ++) above_cost_d += cost[i];
        long long below_cost_d = 0;

        for(int cur_target = 1; cur_target <= data.back().first; cur_target ++){
            cur_cost = cur_cost - above_cost_d + below_cost_d;
            res_cost = min(res_cost, cur_cost);

            while(index < n && data[index].first == cur_target){
                above_cost_d -= data[index].second;
                below_cost_d += data[index].second;
                index ++;
            }
        }
        return res_cost;
    }
};


int main() {

    vector<int> nums1 = {1, 3, 5, 2}, cost1 = {2, 3, 1, 14};
    cout << Solution().minCost(nums1, cost1) << '\n';
    // 8

    vector<int> nums2 = {2, 2, 2, 2, 2}, cost2 = {4, 2, 8, 1, 3};
    cout << Solution().minCost(nums2, cost2) << '\n';
    // 0

    return 0;
}
