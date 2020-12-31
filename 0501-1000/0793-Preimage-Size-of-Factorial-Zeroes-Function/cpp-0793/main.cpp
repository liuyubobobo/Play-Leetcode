/// Source : https://leetcode.com/problems/preimage-size-of-factorial-zeroes-function/description/
/// Author : liuyubobobo
/// Time   : 2018-03-03

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

        int l = 0, r = 1000000000;
        while(l <= r){
            int mid = (l + r) / 2;
            int f_res = f(mid);
            if(f_res == K)
                return 5;
            else if(f_res > K)
                r = mid - 1;
            else
                l = mid + 1;
        }

        return 0;
    }

private:
    int f(int x){
        int res = 0;
        int factor = 5;
        while(factor <= x){
            res += x / factor;
            factor *= 5;
        }
        return res;
    }
};

int main() {

    cout << Solution().preimageSizeFZF(0) << endl;
    cout << Solution().preimageSizeFZF(5) << endl;

    return 0;
}