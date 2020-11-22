/// Source : https://leetcode.com/problems/ways-to-make-a-fair-array/
/// Author : liuyubobobo
/// Time   : 2020-11-21

#include <iostream>
#include <vector>

using namespace std;


/// Presum
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {

        int n = nums.size();
        vector<int> evenpresum(n + 1, 0), oddpresum(n + 1, 0);
        for(int i = 0; i < n; i ++)
            if(i % 2 == 0){
                evenpresum[i + 1] = evenpresum[i] + nums[i];
                oddpresum[i + 1] = oddpresum[i];
            }
            else{
                oddpresum[i + 1] = oddpresum[i] + nums[i];
                evenpresum[i + 1] = evenpresum[i];
            }

        int res = 0;
        for(int i = 0; i < n; i ++){

            int evensum = 0, oddsum = 0;
            if(i) evensum += evenpresum[i], oddsum += oddpresum[i];

            evensum += oddpresum[n] - oddpresum[i + 1];
            oddsum += evenpresum[n] - evenpresum[i + 1];
            if(evensum == oddsum) res ++;
        }
        return res;
    }
};


int main() {

    vector<int> nums1 = {2, 1, 6, 4};
    cout << Solution().waysToMakeFair(nums1) << endl;
    // 1

    vector<int> nums2 = {1, 1, 1};
    cout << Solution().waysToMakeFair(nums2) << endl;
    // 3

    vector<int> nums3 = {1, 2, 3};
    cout << Solution().waysToMakeFair(nums3) << endl;
    // 0

    return 0;
}
