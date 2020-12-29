#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int minMoves(vector<int>& nums, int k) {

        vector<int> pos;
        for(int i = 0; i < nums.size(); i ++)
            if(nums[i]) pos.push_back(i);

        for(int i = 0; i < pos.size(); i ++) pos[i] -= i;
        vector<int> presum(pos.size() + 1, 0);
        for(int i = 0; i < pos.size(); i ++)
            presum[i + 1] = presum[i] + pos[i];

        int res = INT_MAX;
        for(int l = 0; l + k <= pos.size(); l ++){
            int r = l + k - 1;
            int t = presum[r + 1] - presum[r - k/2 + 1] - (presum[l + k/2] - presum[l]);
            res = min(res, t);
        }
        return res;
    }
};


int main() {

    vector<int> nums1 = {1, 0, 0, 1, 0, 1};
    cout << Solution().minMoves(nums1, 2) << endl;
    // 1

    vector<int> nums2 = {1,0,0,0,0,0,1,1};
    cout << Solution().minMoves(nums2, 3) << endl;
    // 5

    vector<int> nums3 = {1,1,0,1};
    cout << Solution().minMoves(nums3, 2) << endl;
    // 0

    return 0;
}
