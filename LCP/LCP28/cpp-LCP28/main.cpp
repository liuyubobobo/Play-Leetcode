/// Source : https://leetcode-cn.com/problems/4xy4Wx/
/// Author : liuyubobobo
/// Time   : 2021-04-04

#include <iostream>
#include <vector>

using namespace std;


/// Binary Search
/// Time Complexity: O(nlogn)
/// Space Complexity: O(1)
class Solution {

private:
    const long long MOD = 1e9 + 7;

public:
    int purchasePlans(vector<int>& nums, int target) {

        sort(nums.begin(), nums.end());
        long long res = 0ll;
        for(int i = 0; i < nums.size(); i ++){

            vector<int>::iterator iter = upper_bound(nums.begin(), nums.end(), target - nums[i]);
            if(iter == nums.begin()) continue;

            iter --;
            if(iter - nums.begin() > i)
                res += (iter - nums.begin()) - i;
        }
        return res % MOD;
    }
};


int main() {

    vector<int> nums1 = {2, 5, 3, 5};
    cout << Solution().purchasePlans(nums1, 6) << endl;
    // 1

    vector<int> nums2 = {2, 2, 1, 9};
    cout << Solution().purchasePlans(nums2, 10) << endl;
    // 4

    return 0;
}
