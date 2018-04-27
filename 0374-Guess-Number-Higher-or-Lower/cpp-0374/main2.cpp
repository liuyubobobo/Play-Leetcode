/// Source : https://leetcode.com/problems/guess-number-higher-or-lower/description/
/// Author : liuyubobobo
/// Time   : 2018-04-27

#include <iostream>
#include <cassert>

using namespace std;

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);


/// Ternary Search
/// Time Complexity: O(log3(n))
/// Space Complexity: O(1)
class Solution {
public:
    int guessNumber(int n) {

        int l = 1, r = n;
        while(l <= r){
            int mid1 = l + (r - l) / 3;
            int mid2 = r - (r - l) / 3;
            int ret1 = guess(mid1);
            if(ret1 == 0)
                return mid1;
            else if(ret1 < 0)
                r = mid1 - 1;
            else{
                int ret2 = guess(mid2);
                if(ret2 == 0)
                    return mid2;
                else if(ret2 < 0){
                    l = mid1 + 1;
                    r = mid2 - 1;
                }
                else
                    l = mid2 + 1;
            }
        }

        assert(false);
    }
};

int main() {

    return 0;
}