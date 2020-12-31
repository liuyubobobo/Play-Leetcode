/// Source : https://leetcode.com/problems/subarray-sums-divisible-by-k/
/// Author : liuyubobobo
/// Time   : 2019-01-21

#include <iostream>
#include <vector>

using namespace std;


/// Pre Sums and Counts
/// Using mod operations to deal with negative numbers
/// See comments below :-)
///
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {

        int n = A.size();
        vector<int> pre(n + 1, 0);
        for(int i = 0; i < n; i ++)
            pre[i + 1] = pre[i] + A[i];

        vector<int> mod(K, 0);
        for(int e: pre)
            mod[((e % K) + K) % K] ++; // deal with negative
            // Attention: a negative number's mod is still negative
            // to make it positive, + K
            // since for positive numbers, +K will make the result >= K,
            // so, we need to % K again

        int res = 0;
        for(int a: mod)
            if(a >= 2) res += a * (a - 1) / 2;

        return res;
    }
};


int main() {

    cout << (-4) % 3 << endl;
    // -1: -4 = -1 * 3 - 1

    return 0;
}