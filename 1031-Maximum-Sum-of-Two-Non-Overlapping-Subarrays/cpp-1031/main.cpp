/// Source : https://leetcode.com/problems/maximum-sum-of-two-non-overlapping-subarrays/
/// Author : liuyubobobo
/// Time   : 2019-04-20

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


/// Pre Sum
/// Time Complexity: O(n^2)
/// Space Complexity: O(n)
class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {

        vector<int> sumL, sumM;

        sumL.push_back(accumulate(A.begin(), A.begin() + L, 0));
        for(int i = L; i < A.size(); i ++)
            sumL.push_back(sumL.back() - A[i - L] + A[i]);
//        for(int e: sumL) cout << e << " "; cout << endl;

        sumM.push_back(accumulate(A.begin(), A.begin() + M, 0));
        for(int i = M; i < A.size(); i ++)
            sumM.push_back(sumM.back() - A[i - M] + A[i]);
//        for(int e: sumM) cout << e << " "; cout << endl;

        int res = 0;
        for(int i = 0; i < sumL.size(); i ++){

            for(int j = 0; j + M - 1 < i; j ++)
                res = max(res, sumL[i] + sumM[j]);

            for(int j = i + L; j < sumM.size(); j ++)
                res = max(res, sumL[i] + sumM[j]);
        }
        return res;
    }
};


int main() {

    vector<int> A1 = {0,6,5,2,2,5,1,9,4};
    cout << Solution().maxSumTwoNoOverlap(A1, 1, 2) << endl;

    return 0;
}