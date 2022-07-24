/// Source : https://leetcode.com/problems/number-of-zero-filled-subarrays/
/// Author : liuyubobobo
/// Time   : 2022-07-23

#include <iostream>
#include <vector>

using namespace std;


/// Split
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {

        int n = nums.size();
        long long res = 0;
        for(int start = 0, i = 1; i <= n; i ++)
            if(i == n || nums[i] != nums[start]){
                if(nums[start] == 0){
                    long long len = i - start;
                    res += (len + 1ll) * len / 2ll;
                }
                start = i;
            }
        return res;
    }
};


int main() {

    return 0;
}
