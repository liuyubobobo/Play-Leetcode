/// Source : https://leetcode.com/problems/maximum-sum-circular-subarray/description/
/// Author : liuyubobobo
/// Time   : 2018-10-08

#include <iostream>
#include <vector>
#include <numeric>
#include <unordered_set>

using namespace std;


/// The result should be 1-interval or 2-intervals
/// Using Kadane's Algorithm to get 1-interval result
/// For 2-interval results, we can also use Kadane's Algorithm's max subarray algorithm
/// Just make every elements in the array into minus :-)
///
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {

        int n = A.size();

        int res = INT_MIN;
        int sum = 0;

        // Kadane's Algorithm
        for(int i = 0; i < n; i ++){
            sum = A[i] + max(sum, 0);
            res = max(res, sum);
        }

        sum = accumulate(A.begin(), A.end(), 0);
        int sum2 = 0;
        for(int i = 0; i < n; i ++){
            sum2 = -A[i] + max(sum2, 0);
            res = max(res, sum + sum2);
        }

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