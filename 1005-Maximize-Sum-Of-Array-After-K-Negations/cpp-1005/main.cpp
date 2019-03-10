/// Source : https://leetcode.com/problems/maximize-sum-of-array-after-k-negations/
/// Author : liuyubobobo
/// Time   : 2019-03-09

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


/// Sorting and Greedy
/// Time Complexity: O(nlogn)
/// Space Complexity: O(1)
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {

        sort(A.begin(), A.end());

        int neg = 0;
        bool hasZero = false;
        for(int i = 0; i < A.size(); i ++)
            if(A[i] < 0) neg ++;
            else if(A[i] == 0) hasZero = true;

        int t = min(neg, K);
        for(int i = 0; i < t; i ++)
            A[i] = -A[i];
        K -= t;

        if(K && !hasZero && K % 2){
            sort(A.begin(), A.end());
            A[0] = -A[0];
        }

        return accumulate(A.begin(), A.end(), 0);
    }
};


int main() {

    vector<int> A1 = {4, 2, 3};
    cout << Solution().largestSumAfterKNegations(A1, 1) << endl;

    return 0;
}