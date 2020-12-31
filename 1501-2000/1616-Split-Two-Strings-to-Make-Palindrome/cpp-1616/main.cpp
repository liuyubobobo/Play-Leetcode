/// Source : https://leetcode.com/problems/split-two-strings-to-make-palindrome/
/// Author : liuyubobobo
/// Time   : 2020-10-10

#include <iostream>
#include <string>

using namespace std;


/// Greedy
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    bool checkPalindromeFormation(string a, string b) {

        if(is_palindrome(a) || is_palindrome(b)) return true;

        int n = a.size(), i = 0, j = n - 1;
        while(i < j)
            if(a[i] == b[j]) i ++, j --;
            else if(is_palindrome(a.substr(i, j - i + 1)) || is_palindrome(b.substr(i, j - i + 1)))
                return true;
            else break;

        if(i >= j) return true;

        i = 0, j = n - 1;
        while(i < j)
            if(b[i] == a[j]) i ++, j --;
            else if(is_palindrome(a.substr(i, j - i + 1)) || is_palindrome(b.substr(i, j - i + 1)))
                return true;
            else break;
        return i >= j;
    }

private:
    bool is_palindrome(const string& s){
        int i = 0, j = s.size() - 1;
        while(i < j)
            if(s[i] != s[j]) return false;
            else i ++, j --;
        return true;
    }
};


int main() {

    cout << Solution().checkPalindromeFormation("x", "y") << endl;
    // 1

    cout << Solution().checkPalindromeFormation("abdef", "fecab") << endl;
    // 1

    cout << Solution().checkPalindromeFormation("ulacfd", "jizalu") << endl;
    // 1

    cout << Solution().checkPalindromeFormation("pvhmupgqeltozftlmfjjde", "yjgpzbezspnnpszebzmhvp") << endl;
    // 1

    cout << Solution().checkPalindromeFormation("xbdef", "xecab") << endl;
    // 0

    return 0;
}
