/// Source : https://leetcode.com/problems/number-of-people-aware-of-a-secret/
/// Author : liuyubobobo
/// Time   : 2022-07-02

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


/// DP with diff array
/// Time Complexity: O(n^2)
/// Space Complexity: O(n)
class Solution {

private:
    const long long MOD = 1e9 + 7;

public:
    int peopleAwareOfSecret(int n, int delay, int forget) {

        vector<long long> diff_pos(n, 0), neg(n, 0);
        diff_pos[0] = 1;
        if(1 < n) diff_pos[1] = MOD - 1;
        long long presum = 0;
        for(int i = 0; i < n; i ++){

            presum += diff_pos[i];
            presum %= MOD;

            if(i + delay < n){
                diff_pos[i + delay] += presum;
                diff_pos[i + delay] %= MOD;
            }

            if(i + forget < n){
                diff_pos[i + forget] -= presum;
                diff_pos[i + forget] += MOD;
                diff_pos[i + forget] %= MOD;

                neg[i + forget] += presum;
                neg[i + forget] %= MOD;
            }
        }

        long long sum_pos = 0;
        presum = 0;
        for(int i = 0; i < n; i ++){
            presum += diff_pos[i];
            presum %= MOD;
            sum_pos += presum;
        }
        long long sum_neg = accumulate(neg.begin(), neg.end(), 0ll);

        return (sum_pos % MOD - sum_neg % MOD + MOD) % MOD;
    }
};


int main() {

    cout << Solution().peopleAwareOfSecret(6, 2, 4) << '\n';
    // 5

    cout << Solution().peopleAwareOfSecret(4, 1, 3) << '\n';
    // 6

    cout << Solution().peopleAwareOfSecret(6, 1, 2) << '\n';
    // 2

    return 0;
}
