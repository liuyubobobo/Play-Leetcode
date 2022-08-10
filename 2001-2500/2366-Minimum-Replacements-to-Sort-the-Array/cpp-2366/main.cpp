/// Source : https://leetcode.com/problems/minimum-replacements-to-sort-the-array/
/// Author : liuyubobobo
/// Time   : 2022-08-10

#include <iostream>
#include <vector>

using namespace std;


/// Greedy
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {

        int n = nums.size();

        long long res = 0;
        int p = nums.back();
        for(int i = n - 2; i >= 0; i --){
            if(nums[i] <= p){
                p = min(p, nums[i]);
                continue;
            }

            int cnt = nums[i] / p;
            int mod = nums[i] % p;
            if(mod) cnt ++;

            res += (cnt - 1);
            p = min(p, nums[i] / cnt);
        }
        return res;
    }
};


int main() {

    vector<int> nums1 = {12,9,7,6,17,19,21};
    cout << Solution().minimumReplacement(nums1) << '\n';
    // 6

    return 0;
}
