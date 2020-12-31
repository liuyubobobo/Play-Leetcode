/// Source : https://leetcode.com/problems/super-palindromes/description/
/// Author : liuyubobobo
/// Time   : 2018-09-16

#include <iostream>
#include <cmath>

using namespace std;


/// Enumerate all base number which can construct a palindrome number
/// and check if the square is also a palindrome number
///
/// Time Complexity: O(sqrt(sqrt(R))*log(R))
/// Space Complexity: O(log(R))
class Solution {
public:
    int superpalindromesInRange(string L, string R) {

        long long lnum = atol(L.c_str());
        long long rnum = atol(R.c_str());
        long long limit = (long long)sqrt(rnum);

        int res = 0;
        for(int k = 0; k <= 1; k ++)
            for(int i = 1; ; i ++){
                long long x = getPalindrome(i, k);
                if(x > limit) break;
                long long square = x * x;
                if(isPalindrome(square) && square >= lnum && square <= rnum)
                    res ++;
            }

        return res;
    }

private:
    long long getPalindrome(int num, bool useLast){
        string num_str = to_string(num);

        string rnum_str = num_str;
        reverse(rnum_str.begin(), rnum_str.end());

        if(useLast) return atol((num_str + rnum_str.substr(1)).c_str());
        return atol((num_str + rnum_str).c_str());
    }

    bool isPalindrome(long long num){
        string s = to_string(num);
        for(int i = 0, j = s.size() - 1; i < j; i ++, j --)
            if(s[i] != s[j])
                return false;
        return true;
    }
};


int main() {

    cout << Solution().superpalindromesInRange("4", "1000") << endl;
    cout << Solution().superpalindromesInRange("1", "5") << endl;

    return 0;
}