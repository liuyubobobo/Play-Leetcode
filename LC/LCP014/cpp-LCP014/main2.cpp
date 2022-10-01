/// Source : https://leetcode-cn.com/problems/qie-fen-shu-zu/
/// Author : liuyubobobo
/// Time   : 2020-04-30

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


/// DP
/// Using p[x] to record the min prime factor of x
/// Time Complexity: O(maxnum*log(maxnum) + nlog(maxnum))
/// Space Complexity: O(maxnum)
class Solution {

public:
    int splitArray(vector<int>& nums) {

        if(nums.size() == 1) return 1;

        int maxnum = *max_element(nums.begin(), nums.end());
        vector<int> p(maxnum + 1, 0);
        for(int i = 2; i <= maxnum; i ++)
            if(!p[i])
                for(int j = i; j <= maxnum; j += i)
                    if(!p[j]) p[j] = i;

        vector<int> best(maxnum + 1, -1);

        int x = nums[0];
        while(x != 1) best[p[x]] = 0, x /= p[x];

        int prev = 1, cur;
        for(int i = 1; i < nums.size(); i ++){

            cur = prev + 1;

            int x = nums[i];
            while(x != 1){
                if(best[p[x]] != -1) cur = min(cur, best[p[x]] + 1);
                x /= p[x];
            }

            x = nums[i];
            while(x != 1){
                best[p[x]] = (best[p[x]] != -1 ? min(best[p[x]], prev) : prev);
                x /= p[x];
            }
            prev = cur;
        }
        return cur;
    }
};


int main() {

    vector<int> nums1 = {2,3,3,2,3,3};
    cout << Solution().splitArray(nums1) << endl;
    // 2

    vector<int> nums2 = {2,3,5,7};
    cout << Solution().splitArray(nums2) << endl;
    // 4

    vector<int> nums3 = {2,4,6,8,10};
    cout << Solution().splitArray(nums3) << endl;
    // 1

    return 0;
}
