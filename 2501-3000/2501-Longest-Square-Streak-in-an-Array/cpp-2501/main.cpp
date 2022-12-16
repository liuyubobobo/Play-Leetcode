/// Source : https://leetcode.com/problems/longest-square-streak-in-an-array/description/
/// Author : liuyubobobo
/// Time   : 2022-12-10

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O(nlogn)
/// Space Compelxity: O(1)
class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {

        int n = nums.size();
        vector<long long> v(n);
        for(int i = 0; i < n; i ++) v[i] = nums[i];

        sort(v.begin(), v.end());
        int res = 0;
        for(int start = 0, i = 1; i <= n; i ++){
            if(i == n || v[i] != v[start]){
                int len = 1;
                long long cur = v[start], cur_index = start;
                while(true){
                    auto iter = lower_bound(v.begin() + cur_index, v.end(), cur * cur);
                    if(iter == v.end() || *iter != cur * cur) break;

                    len ++;
                    cur = cur * cur;
                    cur_index = iter - v.begin();
                }
                res = max(res, len);

                start = i;
            }
        }
        return res >= 2 ? res : -1;
    }
};


int main() {

    return 0;
}
