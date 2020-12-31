/// Source : https://leetcode.com/problems/sqrtx/description/
/// Author : liuyubobobo
/// Time   : 2019-04-03

#include <iostream>

using namespace std;


/// Binary Search
/// Using double first
///
/// Time Complexity: O(log(MAX_INT) * precision)
/// Space Complexity: O(1)
class Solution {

private:
    double e = 1e-6;

public:
    int mySqrt(int x) {

        double l = 0.0, r = INT_MAX;
        while(r - l >= e){
            double mid = (l + r) / 2;
            if(mid * mid <= x)
                l = mid;
            else
                r = mid;
        }
        return (int)r;
    }
};


int main() {

    cout << Solution().mySqrt(4) << endl;
    cout << Solution().mySqrt(8) << endl;

    return 0;
}