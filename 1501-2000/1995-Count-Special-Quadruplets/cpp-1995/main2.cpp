/// Source : https://leetcode.com/problems/count-special-quadruplets/
/// Author : liuyubobobo
/// Time   : 2021-09-04

#include <iostream>
#include <vector>

using namespace std;


/// Using HashMap
/// Time Complexity: O(n^3)
/// Space Complexity: O(n)
class Solution {
public:
    int countQuadruplets(vector<int>& nums) {

        int n = nums.size(), res = 0;
        for(int a = 0; a < n; a ++){
            for(int b = a + 1; b < n; b ++){
                int p = nums[a] + nums[b];
                vector<int> f(101, 0);
                for(int i = b + 1; i < n; i ++){
                    if(nums[i] - p >= 1) res += f[nums[i] - p];
                    f[nums[i]] ++;
                }
            }
        }
        return res;
    }
};


int main() {

    vector<int> nums1 = {1, 2, 3, 6};
    cout << Solution().countQuadruplets(nums1) << endl;
    // 1

    return 0;
}
