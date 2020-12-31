/// Source : https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x/
/// Author : liuyubobobo
/// Time   : 2020-10-04

#include <iostream>
#include <vector>

using namespace std;


/// Counting Sort and Suffix Sum
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int specialArray(vector<int>& nums) {

        int n = nums.size();
        vector<int> cnt(n + 2, 0);
        for(int e: nums) cnt[min(e, n)] ++;

        for(int i = n; i >= 0; i --){
            cnt[i] += cnt[i + 1];
            if(cnt[i] == i) return i;
        }

        return -1;
    }
};


int main() {

    vector<int> nums = {3, 5};
    cout << Solution().specialArray(nums) << endl;
    // 2

    return 0;
}
