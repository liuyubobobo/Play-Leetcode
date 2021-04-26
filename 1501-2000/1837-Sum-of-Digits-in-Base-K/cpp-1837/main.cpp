/// Source : https://leetcode.com/problems/sum-of-digits-in-base-k/
/// Author : liuyubobobo
/// Time   : 2021-04-24

#include <iostream>

using namespace std;


/// K-Based Number
/// Time Complexity: O(logn)
/// Space Complexity: O(1)
class Solution {
public:
    int sumBase(int n, int k) {

        int res = 0;
        while(n){
            res += n % k;
            n /= k;
        }
        return res;
    }
};


int main() {

    return 0;
}
