/// Source : https://leetcode.com/problems/two-sum-less-than-k/
/// Author : liuyubobobo
/// Time   : 2019-06-29

#include <iostream>
#include <vector>

using namespace std;


/// Two Pointers
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int twoSumLessThanK(vector<int>& A, int K) {

        int best = -1;
        for(int i = 0; i < A.size(); i ++)
            for(int j = i + 1; j < A.size(); j ++)
                if(A[i] + A[j] < K)
                    best = max(best, A[i] + A[j]);
        return best;
    }
};


int main() {

    return 0;
}