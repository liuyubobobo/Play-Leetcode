/// Source : https://leetcode.com/problems/break-a-palindrome/
/// Author : liuyubobobo
/// Time   : 2021-09-23

#include <iostream>

using namespace std;


/// Ad-Hoc
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    string breakPalindrome(string palindrome) {

        if(palindrome == "a") return "";

        int n = palindrome.size();
        for(int i = 0; i < n; i ++)
            if(palindrome[i] > 'a'){
                if(n % 2 == 1 && i == n / 2) continue;
                palindrome[i] = 'a';
                return palindrome;
            }

        for(int i = palindrome.size() - 1; i >= 0; i --)
            if(palindrome[i] < 'z'){
                if(n % 2 == 1 && i == n / 2) continue;
                palindrome[i] = 'b';
                return palindrome;
            }

        return "";
    }
};


int main() {

    return 0;
}
