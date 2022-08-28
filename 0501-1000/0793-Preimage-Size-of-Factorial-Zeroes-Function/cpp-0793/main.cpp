/// Source : https://leetcode.com/problems/preimage-size-of-factorial-zeroes-function/description/
/// Author : liuyubobobo
/// Time   : 2018-03-03
/// Updated: 2022-08-28

#include <iostream>

using namespace std;


/// Binary Search
/// Time Complexity: O(logK * logK)
/// Space Complexity: O(1)
class Solution {
public:
    int preimageSizeFZF(int K) {

        if(K == 0)
            return 5;

        long long l = 0ll, r = 5ll * K;
        while(l < r){
            long long mid = (l + r) / 2;
            long long f_res = f(mid);
            if(f_res >= K)
                r = mid;
            else
                l = mid + 1;
        }

        if(f(l) == K){
            return 5 - l % 5;
        }
        return 0;
    }

private:
    long long f(long long x){
        long long res = 0;
        long long factor = 5;
        while(factor <= x){
            res += x / factor;
            factor *= 5;
        }
        return res;
    }
};


int main() {

    cout << Solution().preimageSizeFZF(0) << endl;
    // 5

    cout << Solution().preimageSizeFZF(5) << endl;
    // 0

    cout << Solution().preimageSizeFZF(1000000000) << endl;
    // 5

    return 0;
}