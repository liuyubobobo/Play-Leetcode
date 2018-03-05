/// Source : https://leetcode.com/problems/rotated-digits/description/
/// Author : liuyubobobo
/// Time   : 2018-03-05

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

/// Brute Force
/// Using String
///
/// Time Complexity: O(NlogN)
/// Space Complexity: O(logN)
class Solution {

public:
    int rotatedDigits(int N) {

        int res = 0;
        for(int i = 1 ; i <= N ; i ++){
            string digits = to_string(i);
            string rdigits = digits;
            if(ok(digits, rdigits))
                res ++;
        }
        return res;
    }

private:
    bool ok(const string& digits, string& rdigits){
        for(int i = 0 ; i < rdigits.size() ; i ++)
            if(rdigits[i] == '3' || rdigits[i] == '4' || rdigits[i] == '7')
                return false;
            else if(rdigits[i] == '2')
                rdigits[i] = '5';
            else if(rdigits[i] == '5')
                rdigits[i] = '2';
            else if(rdigits[i] == '6')
                rdigits[i] = '9';
            else if(rdigits[i] == '9')
                rdigits[i] = '6';
        return digits != rdigits;
    }

};

int main() {

    cout << Solution().rotatedDigits(10) << endl;
    return 0;
}