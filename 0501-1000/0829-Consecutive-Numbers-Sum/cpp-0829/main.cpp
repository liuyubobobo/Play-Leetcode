/// Source : https://leetcode.com/problems/consecutive-numbers-sum/
/// Author : liuyubobobo
/// Time   : 2022-06-02

#include <iostream>

using namespace std;


/// Math
/// Time Complexity: O(sqrt(2 * n))
/// Space Complexity: O(1)
class Solution {
public:
    int consecutiveNumbersSum(int n) {

        int A = 2 * n, res = 0;
        for(int i = 1; i * i <= A; i ++)
            if(A % i == 0){
                int x = i, y = - A / i;
                res += ok(x, y);

                x = -i, y = A / i;
                res += ok(x, y);
            }
        return res;
    }

private:
    bool ok(int x, int y){
        int t = x + y + 1;
        return t > 0 && t % 2 == 0;
    }
};


int main() {

    cout << Solution().consecutiveNumbersSum(5) << '\n';
    // 2

    cout << Solution().consecutiveNumbersSum(9) << '\n';
    // 3

    cout << Solution().consecutiveNumbersSum(15) << '\n';
    // 4

    return 0;
}
