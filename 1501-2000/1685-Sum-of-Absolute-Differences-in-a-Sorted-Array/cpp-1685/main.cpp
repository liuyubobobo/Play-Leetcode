/// Source : https://leetcode.com/problems/sum-of-absolute-differences-in-a-sorted-array/
/// Author : liuyubobobo
/// Time   : 2020-12-12

#include <iostream>
#include <vector>

using namespace std;


/// Mathematics
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {

        int n = nums.size();

        int front = 0, tail = 0;
        for(int i = 1; i < n; i ++) tail += nums[i] - nums[0];

        vector<int> res(n, tail);
        for(int i = 1; i < nums.size(); i ++){
            int diff = nums[i] - nums[i - 1];
            tail -= (nums.size() - i) * diff;
            front += i * diff;
            res[i] = front + tail;
        }
        return res;
    }
};


void print_vec(const vector<int>& v){
    for(int e: v) cout << e << " "; cout << endl;
}

int main() {

    vector<int> nums1 = {2, 3, 5};
    print_vec(Solution().getSumAbsoluteDifferences(nums1));
    // 4 3 5

    vector<int> nums2 = {1,4,6,8,10};
    print_vec(Solution().getSumAbsoluteDifferences(nums2));
    // 24,15,13,15,21

    return 0;
}
