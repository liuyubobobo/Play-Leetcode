/// Source : https://leetcode.com/problems/split-two-strings-to-make-palindrome/
/// Author : liuyubobobo
/// Time   : 2020-10-14

#include <iostream>
#include <string>

using namespace std;


/// check from middle
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    bool checkPalindromeFormation(string a, string b) {

        return check(a, b) || check(b, a);
    }

private:
    bool check(const string& a, const string& b){

        int i, j;
        if(a.size() % 2) i = j = a.size() / 2;
        else i = a.size() / 2 - 1, j = a.size() / 2;

        while(i >= 0 && j < a.size() && a[i] == a[j]) i --, j ++;

        int l = i, r = j;
        while(i >= 0 && j < a.size() && a[i] == b[j]) i --, j ++;
        if(i < 0) return true;

        i = l, j = r;
        while(i >= 0 && j < a.size() && b[i] == a[j]) i --, j ++;

        return i < 0;
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
