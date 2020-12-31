/// Source : https://leetcode.com/problems/k-concatenation-maximum-sum/
/// Author : liuyubobobo
/// Time   : 2019-09-14

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


/// Max Subarrray Problem + Presum
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {

private:
    long long MOD = 1e9 + 7;

public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {

        long long res = max(max_subarray(arr), 0);
        if(k == 1) return res % MOD;

        vector<int> psum(arr.size(), arr[0]), max_psum(arr.size(), arr[0]);
        for(int i = 1; i < arr.size(); i ++)
            psum[i] = psum[i - 1] + arr[i],
            max_psum[i] = max(max_psum[i - 1], psum[i]);

        vector<int> ssum(arr.size(), arr.back()), max_ssum(arr.size(), arr.back());
        for(int i = (int)arr.size() - 2; i >= 0; i --)
            ssum[i] = ssum[i + 1] + arr[i],
            max_ssum[i] = max(max_ssum[i + 1], ssum[i]);

        long long sum = accumulate(arr.begin(), arr.end(), 0);
        for(int i = 1; i + 1 < arr.size(); i ++){
            long long t = max_psum[i - 1] + max_ssum[i + 1];
            res = max(res, t);
        }

        if(sum > 0) {
            res = max(res, sum * k);
            res = max(res, (long long) max(0, *max_element(ssum.begin(), ssum.end())) +
                           sum * (long long) (k - 2) +
                           (long long) max(0, *max_element(psum.begin(), psum.end())));
        }
        return res % MOD;
    }

private:
    int max_subarray(const vector<int>& arr){

        vector<int> dp(arr.size(), arr[0]);
        for(int i = 1; i < arr.size(); i ++)
            if(dp[i - 1] < 0) dp[i] = arr[i];
            else dp[i] = dp[i - 1] + arr[i];
        return *max_element(dp.begin(), dp.end());
    }
};


int main() {

    vector<int> arr1 = {1, 2};
    cout << Solution().kConcatenationMaxSum(arr1, 3) << endl;
    // 9

    vector<int> arr2 = {1, -2, 1};
    cout << Solution().kConcatenationMaxSum(arr2, 5) << endl;
    // 2

    vector<int> arr3 = {-1, -2};
    cout << Solution().kConcatenationMaxSum(arr3, 7) << endl;
    // 0

    vector<int> arr4 = {-5, 4, -4, -3, 5, -3};
    cout << Solution().kConcatenationMaxSum(arr4, 3) << endl;
    // 5

    vector<int> arr5 = {-5, -2, 0, 0, 3, 9, -2, -5, 4};
    cout << Solution().kConcatenationMaxSum(arr5, 5) << endl;
    // 20

    return 0;
}