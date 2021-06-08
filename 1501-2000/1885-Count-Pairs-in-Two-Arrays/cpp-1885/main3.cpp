/// Source : https://leetcode.com/problems/count-pairs-in-two-arrays/
/// Author : liuyubobobo
/// Time   : 2021-06-07

#include <iostream>
#include <vector>
#include <set>

using namespace std;


/// Sorting and Two Pointers
/// Time Complexity: O(nlogn)
/// Space Complexity: O(1)
class Solution {
public:
    long long countPairs(vector<int>& nums1, vector<int>& nums2) {

        int n = nums1.size();
        assert(n == nums2.size());
        for(int i = 0; i < n; i ++) nums1[i] -= nums2[i];
//        for(int e: nums1) cout << e << " "; cout << endl;

        sort(nums1.begin(), nums1.end());
        long long res = 0ll;
        for(int i = 0, j = n - 1; i < n; i ++){
            while(j > i && nums1[i] + nums1[j] > 0) j --;
            res += (long long)(n - max(j + 1, i + 1));
        }
        return res;
    }
};


int main() {

    vector<int> nums1 = {2,1,2,1}, nums2 = {1,2,1,2};
    cout << Solution().countPairs(nums1, nums2) << endl;
    // 1

    return 0;
}
