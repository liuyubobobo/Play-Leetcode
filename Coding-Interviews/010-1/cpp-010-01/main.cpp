/// Source : https://leetcode-cn.com/problems/fei-bo-na-qi-shu-lie-lcof/
/// Author : liuyubobobo
/// Time   : 2021-09-03

#include <iostream>

using namespace std;


/// DP
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {

private:
    int MOD = 1e9 + 7;

public:
    int fib(int n) {

        if(n == 0) return 0;
        if(n == 1) return 1;

        int a = 0, b = 1, c;
        for(int i = 2; i <= n; i ++){
            c = (a + b) % MOD;
            a = b;
            b = c;
        }
        return c;
    }
};


int main() {

    cout << Solution().fib(2) << endl;
    cout << Solution().fib(3) << endl;
    cout << Solution().fib(4) << endl;
    cout << Solution().fib(5) << endl;

    return 0;
}
