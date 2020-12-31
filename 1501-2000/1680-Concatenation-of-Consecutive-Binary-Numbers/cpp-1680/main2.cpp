/// Source : https://leetcode.com/problems/concatenation-of-consecutive-binary-numbers/
/// Author : liuyubobobo
/// Time   : 2020-12-05

#include <iostream>
#include <vector>

using namespace std;


/// Two Pointers to get the bit length
/// Time Complexiity: O(n)
/// Space Complexity: O(logn)
class Solution {

private:
    const long long MOD = 1e9 + 7;

public:
    int concatenatedBinary(int n) {

        vector<int> pow2 = {1, 2};
        for(int i = 2; i < 31; i ++)
            pow2.push_back(pow2.back() * 2);

        long long cur = 0;
        int p = 0;
        for(int i = 1; i <= n; i ++){
            if(i == pow2[p + 1]) p ++;
            cur = (cur * pow2[p + 1] + i) % MOD;
        }
        return cur;
    }
};


int main() {

    cout << Solution().concatenatedBinary(1) << endl;
    // 1

    cout << Solution().concatenatedBinary(3) << endl;
    // 27

    cout << Solution().concatenatedBinary(12) << endl;
    // 505379714

    cout << Solution().concatenatedBinary(26042) << endl;
    // 502218269

    return 0;
}