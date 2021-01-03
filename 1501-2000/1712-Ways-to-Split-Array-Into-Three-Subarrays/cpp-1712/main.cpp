/// Source : https://leetcode.com/problems/ways-to-split-array-into-three-subarrays/
/// Author : liuyubobobo
/// Time   : 2021-01-02

#include <iostream>
#include <vector>

using namespace std;


/// Binary Search
/// Using prefix sum and suffix sum
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {

private:
    const int MOD = 1e9 + 7;

public:
    int waysToSplit(vector<int>& nums) {

        int n = nums.size();

        vector<int> presum(n + 1, 0);
        for(int i = 0; i < n; i ++) presum[i + 1] = presum[i] + nums[i];

        vector<int> sufsum(n + 1, 0);
        for(int i = n - 1; i >= 0; i --) sufsum[i] = nums[i] + sufsum[i + 1];

        int res = 0;
        for(int i = 0; i + 2 < n; i ++){
            int lsum1 = presum[i + 1];
            vector<int>::iterator iter1 = lower_bound(presum.begin() + (i + 2), presum.end(), lsum1 + lsum1);
            if(iter1 != presum.end()){
                int a = iter1 - presum.begin() - 1;
                assert(a > i);

                int sum = presum.back() - lsum1;
                int rsum = sum - sum / 2;

                int b = binary_search(sufsum, rsum);
                if(b == n) b --;
                if(b > a) res += (b - a), res %= MOD;
            }
        }
        return res;
    }

    int binary_search(const vector<int>& v, int t){

        int l = 0, r = v.size() - 1;
        while(l < r){
            int mid = (l + r + 1) / 2;
            if(v[mid] >= t) l = mid;
            else r = mid - 1;
        }
        return l;
    }
};


int main() {

    vector<int> nums1 = {1, 1, 1};
    cout << Solution().waysToSplit(nums1) << endl;
    // 1

    vector<int> nums2 = {1, 2, 2, 2, 5, 0};
    cout << Solution().waysToSplit(nums2) << endl;
    // 3

    vector<int> nums3 = {3, 2, 1};
    cout << Solution().waysToSplit(nums3) << endl;
    // 0

    vector<int> nums4 = {0, 3, 3};
    cout << Solution().waysToSplit(nums4) << endl;
    // 1

    vector<int> nums5(1e5, 0);
    cout << Solution().waysToSplit(nums5) << endl;
    // 999849973

    return 0;
}
