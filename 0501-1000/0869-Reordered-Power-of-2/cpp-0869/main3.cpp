/// Source : https://leetcode.com/problems/reordered-power-of-2/description/
/// Author : liuyubobobo
/// Time   : 2018-07-14

#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

/// Counting the digit
///
/// Time Complexity: O((logN)^2)
/// Space Complexity: O(logN)
class Solution {
public:
    bool reorderedPowerOf2(int N) {

        vector<int> freq = getDigitsFreq(N);
        for(int i = 0 ; i <= 30 ; i ++)
            if(freq == getDigitsFreq(1<<i))
                return true;
        return false;
    }

private:
    vector<int> getDigitsFreq(int N){
        vector<int> res(10, 0);
        while(N){
            res[N % 10] ++;
            N /= 10;
        }
        return res;
    }
};


void print_bool(bool res){
    cout << (res ? "True" : "False") << endl;
}

int main() {

    print_bool(Solution().reorderedPowerOf2(1));
    print_bool(Solution().reorderedPowerOf2(10));
    print_bool(Solution().reorderedPowerOf2(16));
    print_bool(Solution().reorderedPowerOf2(24));
    print_bool(Solution().reorderedPowerOf2(46));

    return 0;
}