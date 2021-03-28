/// Source : https://leetcode.com/problems/integer-break/description/
/// Author : liuyubobobo
/// Time   : 2021-03-27

#include <iostream>
#include <vector>

using namespace std;

/// Mathematics
/// Time Complexity: O(log(n))
/// Space Complexity: O(log(n))
class Solution {
public:
    int integerBreak(int n) {

        if(n <= 2) return  1;
        if(n == 3) return 2;

        int n3 = n / 3;
        if(n % 3 == 1) n3 --;

        int res = mypow(3, n3);
        if(n % 3 == 1) res = res * 4;
        if(n % 3 == 2) res = res * 2;
        return res;
    }

private:
    int mypow(int a, int k){

        if(k == 0) return 1;

        int t = mypow(a, k / 2);
        int res = t * t;
        if(k % 2) res = res * a;
        return res;
    }
};


int main() {

    cout << Solution().integerBreak(2) << endl;
    cout << Solution().integerBreak(3) << endl;
    cout << Solution().integerBreak(4) << endl;
    cout << Solution().integerBreak(10) << endl;

    return 0;
}