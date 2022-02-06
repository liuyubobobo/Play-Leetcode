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

        // table[i] 存储的是当前看到有多少个位置，满足从 0 到这个位置，包含的奇数个数为 i
        // table[3] == 5，表示当前已经看到有 5 个位置，从 0 到这个位置包含有 3 个奇数
        unordered_map<int, int> table; // odd_num -> freq

        // 初始的空区间，包含有 0 个奇数
        table[0] = 1;

        // cur 记录 [0, i] 区间一共有多少个奇数
        int cur = 0, res = 0;
        for(int i = 0; i < nums.size(); i ++){
            cur += nums[i] % 2; // 如果 nums[i] 是奇数，cur ++

            // 查找 cur 之前有多少个位置，其奇数个数位 cur - k。
            // 那么从 这些位置 + 1，到 cur，就一共有 k 个奇数
            // 有 k 个奇数的区间数量 += table[cur - k]
            if(table.count(cur - k))
                res += table[cur - k];

            // 把 i 这个位置计算到 table 中
            // 因为 [0, i] 中有 cur 个奇数，所以 table[cur] ++
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
