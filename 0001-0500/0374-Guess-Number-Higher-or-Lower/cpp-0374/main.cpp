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


/// Binary Search
/// Time Complexity: O(logn)
/// Space Complexity: O(1)
class Solution {
public:
    int guessNumber(int n) {

        int l = 1, r = n;
        while(l <= r){
            int mid = l + (r - l) / 2;
            int ret = guess(mid);
            if(ret == 0)
                return mid;
            else if(ret < 0)
                r = mid - 1;
            else
                l = mid + 1;
        }

        assert(false);
    }
};

int main() {

    return 0;
}