/// Source : https://leetcode.com/problems/sqrtx/description/
/// Author : liuyubobobo
/// Time   : 2018-06-18

#include <iostream>

using namespace std;

/// Binary Search
/// Time Complexity: O(long(MAX_INT))
/// Space Complexity: O(1)
class Solution {
public:
    int mySqrt(int x) {

        int l = 0, r = INT_MAX - 1;
        while(l < r){
            long long mid = l + (r - l + 1) / 2;
            if(mid * mid <= (long long)x)
                l = mid;
            else
                r = mid - 1;
        }
        return l;
    }
};

int main() {

    cout << Solution().mySqrt(4) << endl;
    cout << Solution().mySqrt(8) << endl;

    return 0;
}