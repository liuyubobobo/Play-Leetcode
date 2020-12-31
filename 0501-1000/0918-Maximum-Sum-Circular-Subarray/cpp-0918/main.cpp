/// Source : https://leetcode.com/problems/maximum-sum-circular-subarray/description/
/// Author : liuyubobobo
/// Time   : 2018-10-06

#include <iostream>
#include <vector>
#include <numeric>
#include <unordered_set>

using namespace std;


/// Iterate every possible start place
/// For every start point, using Kadane's Algorithm
///
/// Time Complexity: O(n^2)
/// Space Complexity: O(n)
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {

        int n = A.size();
        int res = *max_element(A.begin(), A.end());
        if(res <= 0)
            return res;

        bool hasNegative = false;
        for(int a: A)
            if(a < 0){
                hasNegative = true;
                break;
            }
        if(!hasNegative)
            return accumulate(A.begin(), A.end(), 0);

        unordered_set<int> visited;
        for(int k = 0; k < A.size(); k ++)
            if(A[k] < 0 && A[(k + 1)%n] >= 0 && !visited.count((k + 1)%n)){
                int start = (k + 1) % n;
                int sum = A[start];
                visited.insert(start);
                for(int i = (start + 1) % n; i != start; i = (i + 1) % n){
                    if(sum > 0)
                        sum += A[i];
                    else{
                        start = i;
                        if(visited.count(start))
                            break;
                        visited.insert(start);
                        sum = A[i];
                    }

                    res = max(res, sum);
                }
            }
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