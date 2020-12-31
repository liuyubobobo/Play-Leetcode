/// Source : https://leetcode.com/problems/rotated-digits/description/
/// Author : liuyubobobo
/// Time   : 2018-03-05

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

/// Brute Force
/// We need to write using only digits from 0125689,
/// and write at least one digit from 2569.
///
/// Time Complexity: O(NlogN)
/// Space Complexity: O(logN)
class Solution {

public:
    int rotatedDigits(int N) {

        int res = 0;
        for(int i = 1 ; i <= N ; i ++)
            if(ok(i, false))
                res ++;
        return res;
    }

private:
    bool ok(int num, bool flag){
        if(num == 0)
            return flag;

        int d = num % 10;
        if(d == 3 || d == 4 || d == 7)
            return false;

        if(d == 0 || d == 1 || d == 8)
            return ok(num / 10, flag);

        return ok(num / 10, true);
    }

};

int main() {

    cout << Solution().rotatedDigits(10) << endl;
    return 0;
}