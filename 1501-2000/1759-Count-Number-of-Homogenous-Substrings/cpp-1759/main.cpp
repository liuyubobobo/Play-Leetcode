/// Source : https://leetcode.com/problems/count-number-of-homogenous-substrings/
/// Author : liuyubobobo
/// Time   : 2021-02-13

#include <iostream>
#include <vector>

using namespace std;


/// Linear Scan
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int countHomogenous(string s) {

        long long res = 0ll, MOD = 1e9 + 7;
        for(int start = 0, i = 1; i <= s.size(); i ++)
            if(i == s.size() || s[i] != s[start]){

                int len = i - start;
                res += (1ll + (long long)len) * (long long)len / 2ll;
                res %= MOD;

                start = i;
                i = start;
            }
        return res;
    }
};


int main() {

    return 0;
}
