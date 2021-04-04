/// Source : https://leetcode.com/problems/minimum-absolute-sum-difference/
/// Author : liuyubobobo
/// Time   : 2021-04-03

#include <iostream>
#include <vector>

using namespace std;


/// Binary Search
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {

        long long sum = 0ll;
        for(int i = 0; i < nums1.size(); i ++)
            sum += (long long)abs(nums1[i] - nums2[i]);

        vector<int> v = nums1;
        sort(v.begin(), v.end());

        long long res = sum;
        for(int i = 0; i < nums1.size(); i ++){

            vector<int>::iterator iter = lower_bound(v.begin(), v.end(), nums2[i]);
            if(iter != v.end())
                res = min(res, sum - (long long)abs(nums1[i] - nums2[i]) + (long long)abs(*iter - nums2[i]));

            if(iter != v.begin()){
                iter --;
                res = min(res, sum - (long long)abs(nums1[i] - nums2[i]) + (long long)abs(*iter - nums2[i]));
            }
        }

        return res % (long long)(1e9 + 7);
    }
};


int main() {

    vector<int> nums11 = {1, 7, 5}, nums12 = {2, 3, 5};
    cout << Solution().minAbsoluteSumDiff(nums11, nums12) << endl;
    // 3

    vector<int> nums21 = {2, 4, 6, 8, 10}, nums22 = {2, 4, 6, 8, 10};
    cout << Solution().minAbsoluteSumDiff(nums21, nums22) << endl;
    // 0

    vector<int> nums31 = {1,10,4,4,2,7}, nums32 = {9,3,5,1,7,4};
    cout << Solution().minAbsoluteSumDiff(nums31, nums32) << endl;
    // 20

    return 0;
}
