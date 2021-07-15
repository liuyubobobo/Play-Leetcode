/// Source : https://leetcode.com/problems/valid-triangle-number/
/// Author : liuyubobobo
/// Time   : 2021-07-15

#include <iostream>
#include <vector>

using namespace std;


/// Binary Search
/// Time Complexity: O(n^2 * logn)
/// Space Complexity: O(1)
class Solution {
public:
    int triangleNumber(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        int n = nums.size(), res = 0;
        for(int i = 0; i < n; i ++)
            for(int j = i + 1; j < n; j ++){
                int a = nums[i], b = nums[j];
                vector<int>::iterator iter1 = upper_bound(nums.begin() + (j + 1), nums.end(), b - a);
                int l = iter1 - nums.begin();

                vector<int>::iterator iter2 = lower_bound(nums.begin() + (j + 1), nums.end(), b + a);
                iter2 --;
                int r = iter2 - nums.begin();

//                cout << i << ' ' << j << " : " << l << ' ' << r << endl;
                if(l <= r) res += (r - l + 1);
            }
        return res;
    }
};


int main() {

    vector<int> nums1 = {2, 2, 3, 4};
    cout << Solution().triangleNumber(nums1) << endl;

    return 0;
}
