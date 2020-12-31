/// Source : https://leetcode.com/problems/maximum-subarray-sum-with-one-deletion/
/// Author : liuyubobobo
/// Time   : 2019-09-08

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


/// Forward and Backward Maximum Subarray
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int maximumSum(vector<int>& arr) {

        int n = arr.size();
        if(n == 1) return arr[0];

        vector<int> dp1(n, 0);
        dp1[0] = arr[0];
        for(int i = 1; i < n; i ++)
            if(dp1[i - 1] <= 0) dp1[i] = arr[i];
            else dp1[i] = arr[i] + dp1[i - 1];

        int res = *max_element(dp1.begin(), dp1.end());
        vector<int> dp2(n, 0);
        dp2[n - 1] = arr[n - 1];
        for(int i = n - 2; i >= 0; i --) {
            if (dp2[i + 1] <= 0) dp2[i] = arr[i];
            else dp2[i] = arr[i] + dp2[i + 1];

            if(i - 1 >= 0)
                res = max(res, dp2[i + 1] + dp1[i - 1]);
        }

        return res;
    }
};


int main() {

    vector<int> arr1 = {1, -2, 0, 3};
    cout << Solution().maximumSum(arr1) << endl;
    // 4

    vector<int> arr2 = {1, -2, -2, 3};
    cout << Solution().maximumSum(arr2) << endl;
    // 3

    vector<int> arr3 = {-1, -1, -1, -1};
    cout << Solution().maximumSum(arr3) << endl;
    // -1

    vector<int> arr4 = {8, -1, 6, -7, -4, 5, -4, 7, -6};
    cout << Solution().maximumSum(arr4) << endl;
    // 17

    return 0;
}