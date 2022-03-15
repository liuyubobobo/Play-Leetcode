/// Source : https://leetcode.com/problems/sqrtx/description/
/// Author : liuyubobobo
/// Time   : 2022-03-16

#include <iostream>

using namespace std;


/// Taylor Series Expansion
/// Time Complexity: iterative count
/// Space Complexity: O(1)
class Solution {

private:
    double e = 1e-5;

public:
    int mySqrt(int x) {

        if(!x) return x;

        double a = x / 2.0;
        while(true){
            double next_a = a - (a * a - (double)x) / (2.0 * a);
            if(abs(next_a - a) < e) break;
            a = next_a;
        }
        return (int)a;
    }
};


int main() {

    cout << Solution().mySqrt(4) << endl;
    cout << Solution().mySqrt(8) << endl;

    return 0;
}