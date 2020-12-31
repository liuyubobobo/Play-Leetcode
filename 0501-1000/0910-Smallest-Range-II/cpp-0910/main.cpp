/// Source : https://leetcode.com/problems/smallest-range-ii/description/
/// Author : liuyubobobo
/// Time   : 2018-09-22

#include <iostream>
#include <vector>

using namespace std;


/// Sorting and Greedy
/// Time Complexity: O(nlogn)
/// Space Complexity: O(1)
class Solution {
public:
    int smallestRangeII(vector<int>& A, int K) {

        sort(A.begin(), A.end());
        int res = A.back() - A[0];
        for(int i = 0; i < A.size() - 1; i ++)
            res = min(res,
                      max(A[i] + K, A.back() - K) - min(A[0] + K, A[i + 1] - K));
        return res;
    }
};


int main() {

    return 0;
}