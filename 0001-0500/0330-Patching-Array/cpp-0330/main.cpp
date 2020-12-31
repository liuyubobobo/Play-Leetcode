#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int minPatches(vector<int>& nums, int n) {

        long long r = 0ll;
        int res = 0, i = 0;
        while(r < n)
            if(i < nums.size() && nums[i] <= r + 1)
                r += nums[i ++];
            else
                res ++, r += (r + 1);
        return res;
    }
};


int main() {

    vector<int> nums1 = {1, 3};
    cout << Solution().minPatches(nums1, 6) << endl;
    // 1

    vector<int> nums2 = {1, 5, 10};
    cout << Solution().minPatches(nums2, 20) << endl;
    // 2

    vector<int> nums3 = {1, 2, 2};
    cout << Solution().minPatches(nums3, 5) << endl;
    // 0

    vector<int> nums4 = {};
    cout << Solution().minPatches(nums4, 7) << endl;
    // 3

    return 0;
}
