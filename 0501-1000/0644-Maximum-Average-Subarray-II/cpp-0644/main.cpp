/// Source : https://leetcode.com/problems/maximum-average-subarray-ii/
/// Author : liuyubobobo
/// Time   : 2021-02-05

#include <iostream>
#include <vector>

using namespace std;


/// Binary Search
/// Time Complexity: O(nlog(maxv * 10^5))
/// Space Complexity: O(1)
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {

        int minv = *min_element(nums.begin(), nums.end());
        int maxv = *max_element(nums.begin(), nums.end());

        double l = minv, r = maxv;
        while(r - l >= 1e-5){
//            cout << l << " " << r << endl;
            double mid = (l + r) / 2.0;
            if(ok(nums, k, mid)) l = mid;
            else r = mid;
        }
        return l;
    }

private:
    bool ok(const vector<int>& nums, int k, double average){

        double sum = 0.0;
        for(int i = 0; i < k; i ++)
            sum += nums[i] - average;

        if(sum >= 0) return true;
        double premin = 0, presum = 0.0;
        for(int i = k; i < nums.size(); i ++){
            sum += nums[i] - average;
            presum += (nums[i - k] - average);

            premin = min(premin, presum);
            if(sum - premin >= 0) return true;
        }
        return false;
    }
};


int main() {

    vector<int> nums1 = {1,12,-5,-6,50,3};
    cout << Solution().findMaxAverage(nums1, 4) << endl;
    // 12.75

    vector<int> nums2 = {5};
    cout << Solution().findMaxAverage(nums2, 1) << endl;
    // 5

    vector<int> nums3 = {8,9,3,1,8,3,0,6,9,2};
    cout << Solution().findMaxAverage(nums3, 8) << endl;
    // 5.22222

    return 0;
}
