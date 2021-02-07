/// Source : https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/
/// Author : liuyubobobo
/// Time   : 2021-02-06

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O(n^2)
/// Space Complexity: O(1)
class Solution {
public:
    bool check(vector<int>& nums) {

        for(int i = 0; i < nums.size(); i ++)
            if(ok(nums, i)) return true;
        return false;
    }

private:
    bool ok(const vector<int>& nums, int start){

        int n = nums.size();
        for(int i = 1; i < n; i ++)
            if(nums[(start + i) % n] < nums[(start + i - 1) % n]) return false;
        return true;
    }
};


int main() {

    vector<int> nums1 = {2, 1, 3, 4};
    cout << Solution().check(nums1) << endl;
    // 0

    return 0;
}
