/// Source : https://leetcode.com/problems/maximum-sum-circular-subarray/description/
/// Author : liuyubobobo
/// Time   : 2018-10-06

#include <iostream>
#include <vector>
#include <numeric>
#include <unordered_set>

using namespace std;


/// The result should be 1-interval or 2-intervals
/// Using lmin and rmin to get 1-interval result
/// Using lmax and rmax to get 2-interval result
///
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {

        int n = A.size();

        vector<int> lmin(n + 1, 0);
        int sum = 0;
        for(int i = 0; i < n; i ++){
            sum += A[i];
            lmin[i + 1] = min(lmin[i], sum);
        }

        vector<int> rmin(n + 1, 0);
        sum = 0;
        for(int i = n - 1; i >= 0; i --){
            sum += A[i];
            rmin[i] = min(rmin[i + 1], sum);
        }

        vector<int> lmax(n + 1, 0);
        sum = 0;
        for(int i = 0; i < n; i ++){
            sum += A[i];
            lmax[i + 1] = max(lmax[i], sum);
        }

        vector<int> rmax(n + 1, 0);
        sum = 0;
        for(int i = n - 1; i >= 0; i --){
            sum += A[i];
            rmax[i] = max(rmax[i + 1], sum);
        }

        sum = accumulate(A.begin(), A.end(), 0);
        int res = INT_MIN;
        for(int i = 0; i <= n; i ++)
            res = max(res, sum - lmin[i] - rmin[i]);
        for(int i = 0; i <= n; i ++)
            res = max(res, lmax[i] + rmax[i]);

        if(res == 0)
            res = *max_element(A.begin(), A.end());
        return res;
    }
};


int main() {

    vector<int> A1 = {1,-2,3,-2};
    cout << Solution().maxSubarraySumCircular(A1) << endl;
    // 3

    vector<int> A2 = {5,-3,5};
    cout << Solution().maxSubarraySumCircular(A2) << endl;
    // 10

    vector<int> A3 = {3,-1,2,-1};
    cout << Solution().maxSubarraySumCircular(A3) << endl;
    // 4

    vector<int> A4 = {3,-2,2,-3};
    cout << Solution().maxSubarraySumCircular(A4) << endl;
    // 3

    vector<int> A5 = {-2,-3,-1};
    cout << Solution().maxSubarraySumCircular(A5) << endl;
    // -1

    vector<int> A6 = {-2,4,-5,4,-5,9,4};
    cout << Solution().maxSubarraySumCircular(A6) << endl;
    // 15

    vector<int> A7 = {-5,4,-6};
    cout << Solution().maxSubarraySumCircular(A7) << endl;
    // 4

    vector<int> A8 = {-5,-2,5,6,-2,-7,0,2,8};
    cout << Solution().maxSubarraySumCircular(A7) << endl;
    // 4

    return 0;
}