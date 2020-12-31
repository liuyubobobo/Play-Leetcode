/// Source : https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/
/// Author : liuyubobobo
/// Time   : 2020-05-09

#include <iostream>
#include <vector>

using namespace std;


/// Presum + Brute Force
/// Time Complexity: O(n^3)
/// Space Complexity: O(n)
class Solution {
public:
    int countTriplets(vector<int>& arr) {

        int n = arr.size();
        vector<int> pre(n + 1, 0);
        for(int i = 0; i < arr.size(); i ++)
            pre[i + 1] = pre[i] ^ arr[i];

        int res = 0;
        for(int i = 0; i < n; i ++)
            for(int j = i + 1; j < n; j ++)
                for(int k = j; k < n; k ++)
                    if(pre[j] ^ pre[i] == pre[k + 1] ^ pre[j])
                        res ++;
        return res;
    }
};


int main() {

    vector<int> nums1 = {2, 3, 1, 6, 7};
    cout << Solution().countTriplets(nums1) << endl;
    // 4

    vector<int> nums2 = {1, 1, 1, 1, 1};
    cout << Solution().countTriplets(nums2) << endl;
    // 10

    vector<int> nums3 = {2, 3};
    cout << Solution().countTriplets(nums3) << endl;
    // 0

    vector<int> nums4 = {7,11,12,9,5,2,7,17,22};
    cout << Solution().countTriplets(nums4) << endl;
    // 8

    return 0;
}
