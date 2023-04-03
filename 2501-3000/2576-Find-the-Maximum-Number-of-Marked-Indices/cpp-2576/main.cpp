/// Source : https://leetcode.com/problems/find-the-maximum-number-of-marked-indices/description/
/// Author : liuyubobobo
/// Time   : 2023-02-27

#include <iostream>
#include <vector>
#include <set>

using namespace std;


/// Greedy
/// Time Complexity: O(nlogn)
/// Space Complexity: O(1)
class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        int n = nums.size(), res = 0;
        for(int i = 0, j = n / 2; i < n / 2 && j < n; i ++){
            while(j < n && nums[i] * 2 > nums[j]) j ++;
            if(j < n) res += 2, j ++;
        }
        return res;
    }
};


int main() {

    vector<int> nums1 = {42,83,48,10,24,55,9,100,10,17,17,99,51,32,16,98,99,31,28,68,71,14,64,29,15,40};
    cout << Solution().maxNumOfMarkedIndices(nums1) << '\n';
    // 26

    return 0;
}
