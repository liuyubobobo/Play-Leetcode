/// Source : https://leetcode.com/problems/broken-calculator/
/// Author : liuyubobobo
/// Time   : 2019-02-09

#include <iostream>
#include <cassert>

using namespace std;


/// Greedy
/// Time Complexity: O(logY)
/// Space Complexity: O(1)
class Solution {
public:
    int brokenCalc(int X, int Y) {

        if(X >= Y) return X - Y;

        int res = 0;
        while(X != Y){
            if(Y % 2) res ++, Y ++;
            else res ++, Y /= 2;

            if(X > Y)
                return res + X - Y;
        }

        return res;
    }
};


int main() {

    cout << Solution().brokenCalc(2, 3) << endl;
    // 2

    cout << Solution().brokenCalc(5, 8) << endl;
    // 2

    cout << Solution().brokenCalc(3, 10) << endl;
    // 3

    cout << Solution().brokenCalc(1024, 1) << endl;
    // 1023

    cout << Solution().brokenCalc(1, 1000000000) << endl;
    // 39

    return 0;
}