/// Source : https://leetcode.com/problems/equal-sum-arrays-with-minimum-number-of-operations/
/// Author : liuyubobobo
/// Time   : 2021-02-27

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


/// Greedy
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {

        int n1 = nums1.size(), n2 = nums2.size();
        if(6 * n1 < n2 || 6 * n2 < n1) return -1;

        int sum1 = accumulate(nums1.begin(), nums1.end(), 0);
        int sum2 = accumulate(nums2.begin(), nums2.end(), 0);
        if(sum1 == sum2) return 0;

        if(sum1 > sum2){
            swap(n1, n2);
            swap(sum1, sum2);
            swap(nums1, nums2);
        }

        vector<int> f1(7, 0), f2(7, 0);
        for(int e: nums1) f1[e] ++;
        for(int e: nums2) f2[e] ++;

        int res = 0;
        for(int i = 1; i <= 5; i ++){

            int a = i, b = 7 - i;
            for(int i = 0; i < f1[a]; i ++){
                sum1 += (6 - a);
                res ++;
                if(sum1 >= sum2) return res;
            }

            for(int i = 0; i < f2[b]; i ++){
                sum2 -= (b - 1);
                res ++;
                if(sum1 >= sum2) return res;
            }
        }
        return res;
    }
};


int main() {

    vector<int> nums11 = {1,2,3,4,5,6}, nums12 = {1,1,2,2,2,2};
    cout << Solution().minOperations(nums11, nums12) << endl;
    // 3

    vector<int> nums21 = {1,1,1,1,1,1,1}, nums22 = {6};
    cout << Solution().minOperations(nums21, nums22) << endl;
    // -1

    vector<int> nums31 = {6, 6}, nums32 = {1};
    cout << Solution().minOperations(nums31, nums32) << endl;
    // 3

    vector<int> nums41 = {5,6,4,3,1,2}, nums42 = {6,3,3,1,4,5,3,4,1,3,4};
    cout << Solution().minOperations(nums41, nums42) << endl;
    // 4

    return 0;
}
