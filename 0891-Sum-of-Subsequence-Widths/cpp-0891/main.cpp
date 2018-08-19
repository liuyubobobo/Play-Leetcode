/// Source : https://leetcode.com/problems/sum-of-subsequence-widths/description/
/// Author : liuyubobobo
/// Time   : 2018-08-19

#include <iostream>
#include <vector>

using namespace std;


/// Mathematics
/// Time Complexity: O(nlogn)
/// Space Complexity : O(1);
class Solution {

private:
    long long MOD = 1e9 + 7;

public:
    int sumSubseqWidths(vector<int>& A) {

        sort(A.begin(), A.end());
        int n = A.size();

        long long res = (power(2ll, n - 1) - 1ll) * (long long)A.back() % MOD;
        res = (res - (power(2ll, n - 1) - 1ll) * (long long)A[0] % MOD) % MOD;
        for(int i = 1; i < A.size() - 1 ; i ++){
            int left = i, right = n - (i + 1);
            res = (res + (power(2ll, left) - 1ll) * (long long)A[i] % MOD) % MOD;
            res = (res - (power(2ll, right) - 1ll) * (long long)A[i] % MOD) % MOD;
        }
        return res;
    }

private:
    long long power(long long a, long long b){

        if(b == 0ll)
            return 1ll;

        long long t = power(a, b / 2ll);
        long long ret = t * t % MOD;
        if(b % 2ll == 1ll)
            ret = ret * a % MOD;
        return ret;
    }
};


int main() {

    vector<int> nums = {2, 1, 3};
    cout << Solution().sumSubseqWidths(nums) << endl;

    return 0;
}