/// Source : https://leetcode.com/problems/count-number-of-nice-subarrays/
/// Author : liuyubobobo
/// Time   : 2022-02-04

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


/// Presum + Map
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {

        unordered_map<int, int> table; // odd_num -> freq
        table[0] = 1;

        int cur = 0, res = 0;
        for(int e: nums){
            cur += e % 2;
            if(table.count(cur - k))
                res += table[cur - k];
            table[cur] ++;
        }
        return res;
    }
};


int main() {

    vector<int> nums1 = {1, 1, 2, 1, 1};
    cout << Solution().numberOfSubarrays(nums1, 3) << endl;
    // 2

    return 0;
}
