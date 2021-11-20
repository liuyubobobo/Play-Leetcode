/// Source : https://leetcode.com/problems/integer-replacement/
/// Author : liuyubobobo
/// Time   : 2021-11-18

#include <iostream>

using namespace std;


/// Greedy
/// Time Complexity: O(logn)
/// Space Complexity: O(1)
class Solution {
public:
    int integerReplacement(long long n) {

        int res = 0;
        while(n != 1){
            if(n == 3) n = 1, res += 2;
            else if(n % 2 == 0) res ++, n /= 2;
            else if((n + 1) % 4 == 0) n ++, res ++;
            else n --, res ++;
        }
        return res;
    }
};


int main() {

    return 0;
}
