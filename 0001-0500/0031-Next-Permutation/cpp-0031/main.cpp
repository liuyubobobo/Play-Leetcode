/// Source : https://leetcode.com/problems/next-permutation/
/// Author : liuyubobobo
/// Time   : 2021-05-04

#include <iostream>
#include <vector>

using namespace std;


/// next permutation
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        int i;
        for(i = nums.size() - 1; i >= 1; i --)
            if(nums[i - 1] < nums[i]) break;

        if(i == 0){
            reverse(nums.begin(), nums.end());
            return;
        }

        int j;
        for(j = nums.size() - 1; j > i; j --)
            if(nums[j] > nums[i - 1]) break;

        swap(nums[i - 1], nums[j]);
        reverse(nums.begin() + i, nums.end());
    }
};


bool is_sorted(const vector<int>& v){
    for(int i = 1; i < v.size(); i ++)
        if(v[i - 1] > v[i]) return false;
    return true;
}

void print_vec(const vector<int>& v){
    for(int e: v) cout << e << " "; cout << endl;
}

int main() {

    vector<int> nums1 = {1, 2, 3};
    Solution().nextPermutation(nums1);
    print_vec(nums1);
    // 1 3 2

    vector<int> nums2 = {1, 2, 2};
    do{
        Solution().nextPermutation(nums2);
        print_vec(nums2);
    }while(!is_sorted(nums2));

    return 0;
}
