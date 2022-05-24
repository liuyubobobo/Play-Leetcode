/// Source : https://leetcode.com/problems/132-pattern/
/// Author : liuyubobobo
/// Time   : 2021-03-23
/// Updated: 2022-05-24

#include <iostream>
#include <vector>
#include <set>

using namespace std;


/// Reverse to find 32-pattern first and greedily check 1-part
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    bool find132pattern(vector<int>& nums) {

        int n = nums.size();
        if(n <= 2) return false;

        set<int, greater<int>> s;
        s.insert(nums[n - 1]);
        s.insert(nums[n - 2]);
        int t = nums[n - 2] > nums[n - 1] ? nums[n - 1] : INT_MIN;

        for(int i = n - 3; i >= 0; i --){
            if(nums[i] < t) return true;

            auto iter = s.upper_bound(nums[i]);
            if(iter != s.end())
                t = max(t, *iter);
            s.insert(nums[i]);
        }

        return false;
    }
};


int main() {

    vector<int> nums1 = {1, 2, 3, 4};
    cout << Solution().find132pattern(nums1) << endl;
    // 0

    vector<int> nums2 = {1, 0, 1, -4, -3};
    cout << Solution().find132pattern(nums2) << endl;
    // 0

    vector<int> nums3 = {1, 3, 2, 4, 5};
    cout << Solution().find132pattern(nums3) << endl;
    // 1

    return 0;
}
