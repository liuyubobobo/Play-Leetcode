/// Source : https://leetcode.com/problems/minimum-operations-to-make-the-array-k-increasing/
/// Author : liuyubobobo
/// Time   : 2021-12-18

#include <iostream>
#include <vector>

using namespace std;


/// LIS
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    int kIncreasing(vector<int>& arr, int k) {

        int n = arr.size();

        int res = 0;
        for(int start = 0; start < k; start ++){
            vector<int> A;
            for(int i = start; i < n; i += k) A.push_back(arr[i]);
            res += A.size() - lis(A);
        }
        return res;
    }

private:
    int lis(const vector<int>& A){

        vector<int> dp;
        for(int e: A)
            if(dp.empty() || e >= dp.back())
                dp.push_back(e);
            else
                dp[upper_bound(dp.begin(), dp.end(), e) - dp.begin()] = e;
        return dp.size();
    }
};


int main() {

    vector<int> arr1 = {5,4,3,2,1};
    cout << Solution().kIncreasing(arr1, 1) << endl;
    // 4

    vector<int> arr2 = {4,1,5,2,6,2};
    cout << Solution().kIncreasing(arr2, 2) << endl;
    // 0

    vector<int> arr3 = {4,1,5,2,6,2};
    cout << Solution().kIncreasing(arr3, 3) << endl;
    // 2

    vector<int> arr4 = {2,2,2,2,2,1,1,4,4,3,3,3,3,3};
    cout << Solution().kIncreasing(arr4, 1) << endl;
    // 4

    return 0;
}
