/// Source : https://leetcode.com/problems/subarray-sums-divisible-by-k/
/// Author : liuyubobobo
/// Time   : 2019-01-12

#include <iostream>
#include <vector>

using namespace std;


/// Pre Sums and Counts
/// to deal with negative number, calculate an offset to make all numbers positive
///
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {

        int v = *min_element(A.begin(), A.end());
        if(v < 0){
            int x = 0;
            while(v < 0) v += K, x += K;

            for(int &e: A) e += x;
        }

        int n = A.size();
        vector<int> pre(n + 1, 0);
        for(int i = 0; i < n; i ++)
            pre[i + 1] = pre[i] + A[i];

        vector<int> mod(K, 0);
        for(int e: pre)
            mod[e % K] ++;

        int res = 0;
        for(int a: mod)
            if(a >= 2) res += a * (a - 1) / 2;

        return res;
    }
};


int main() {

    vector<int> A1 = {4,5,0,-2,-3,1};
    cout << Solution().subarraysDivByK(A1, 5) << endl;
    // 7

    return 0;
}