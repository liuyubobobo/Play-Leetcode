/// Source : https://leetcode.com/problems/convert-integer-to-the-sum-of-two-no-zero-integers/
/// Author : liuyubobobo
/// Time   : 2020-01-11

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O(nlogn)
/// Space Complexity: O(1)
class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {

        for(int i = 1; i <= n / 2; i ++)
            if(ok(i) && ok(n - i)) return {i, n - i};
        return {};
    }

private:
    bool ok(int x){
        while(x){
            if(x % 10 == 0) return false;
            x /= 10;
        }
        return true;
    }
};


int main() {

    return 0;
}
