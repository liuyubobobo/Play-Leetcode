/// Source : https://leetcode.com/problems/number-of-subarrays-with-lcm-equal-to-k/
/// Author : liuyubobobo
/// Time   : 2022-11-12

#include <iostream>
#include <vector>

using namespace std;


/// Ad-Hoc
/// Time Complexity: O(n^2 * logk)
/// Space Complexity: O(1)
class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {

        int n = nums.size(), res = 0;
        for(int l = 0; l < n; l ++){
            int lcm = nums[l];
            if(lcm == k) res ++;
            else if(lcm > k) continue;
            for(int r = l + 1; r < n && lcm <= k; r ++){
                lcm = lcm * nums[r] / gcd(lcm, nums[r]);
                if(lcm == k) res ++;
            }
        }
        return res;
    }

private:
    int gcd(int a, int b){

        if(a < b) swap(a, b);
        int c;
        while (b){
            c = a % b;
            a = b;
            b = c;
        }
        return a;
    }
};


int main() {

    vector<int> nums1 = {3, 6, 2, 7, 1};
    cout << Solution().subarrayLCM(nums1, 6) << '\n';

    return 0;
}
