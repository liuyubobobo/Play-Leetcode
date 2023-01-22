/// Source : https://leetcode.com/problems/count-the-number-of-good-subarrays/description/
/// Author : liuyubobobo
/// Time   : 2023-01-14

#include <iostream>
#include <vector>
#include <map>

using namespace std;


/// Sliding Window
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    long long countGood(vector<int>& nums, int k) {

        map<int, int> f;
        long long cur = 0, res = 0;
        int n = nums.size(), l = 0, r = -1;
        while(l < n){
            if(r + 1 < n && cur < k){
                cur += f[nums[r + 1]];
                f[nums[r + 1]] ++;
                r ++;
            }
            else{
                f[nums[l]] --;
                cur -= f[nums[l]];
                l ++;
            }
            if(cur >= k) res += n - r;
        }
        return res;
    }
};


int main() {

    return 0;
}
