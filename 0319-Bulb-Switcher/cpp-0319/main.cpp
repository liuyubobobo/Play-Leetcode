/// Source : https://leetcode.com/problems/bulb-switcher/description/
/// Author : liuyubobobo
/// Time   : 2017-12-01

#include <iostream>
#include <cassert>

using namespace std;

/// For every number, see whether the divisor number is odd
/// Time Complexity: O(n*sqrt(n))
/// Space Complexity: O(1)
///
/// Time Limit Exceed!!!
class Solution {

public:
    int bulbSwitch(int n) {

        assert(n >= 0);

        if(n <= 1)
            return n;

        int count = 1;
        for(int i = 2 ; i <= n ; i ++)
            if(divisorNumber(i) % 2 == 1)
                count += 1;
        return count;
    }

private:
    int divisorNumber(int x){
        int ret = 0;
        for(int i = 1 ; i * i <= x ; i ++)
            if(x % i == 0){
                ret += 1;
                if(x / i != i)
                    ret += 1;
            }
        return ret;
    }
};

int main() {

    cout << Solution().bulbSwitch(2) << endl;
    cout << Solution().bulbSwitch(3) << endl;

    return 0;
}