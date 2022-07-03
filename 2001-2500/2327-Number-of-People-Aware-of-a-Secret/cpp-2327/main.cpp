/// Source : https://leetcode.com/problems/number-of-people-aware-of-a-secret/
/// Author : liuyubobobo
/// Time   : 2022-07-02

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


/// DP
/// Time Complexity: O(n^2)
/// Space Complexity: O(n)
class Solution {

private:
    const long long MOD = 1e9 + 7;

public:
    int peopleAwareOfSecret(int n, int delay, int forget) {

        vector<long long> pos(n, 0), neg(n, 0);
        pos[0] = 1;
        for(int i = 0; i < n; i ++){

            for(int j = delay; j < forget && i + j < n; j ++){
                pos[i + j] += pos[i];
                pos[i + j] %= MOD;
            }

            if(i + forget < n){
                neg[i + forget] += pos[i];
                neg[i + forget] %= MOD;
            }
        }

        long long sum_pos = accumulate(pos.begin(), pos.end(), 0ll);
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
