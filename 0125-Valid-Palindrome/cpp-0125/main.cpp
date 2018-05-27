/// Source : https://leetcode.com/problems/valid-palindrome/description/
/// Author : liuyubobobo
/// Time   : 2018-05-27

#include <iostream>

using namespace std;


/// Two Pointers
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {

public:
    bool isPalindrome(string s) {

        int i = next_alpha_numeric(s, 0);
        int j = prev_alpha_numeric(s, s.size() - 1);
        while(i <= j){
            if(tolower(s[i]) != tolower(s[j]))
                return false;
            i = next_alpha_numeric(s, i + 1);
            j = prev_alpha_numeric(s, j - 1);
        }
        return true;
    }

private:
    int next_alpha_numeric(const string& s, int index){
        for(int i = index ; i < s.size() ; i ++)
            if(isalnum(s[i]))
                return i;
        return s.size();
    }

    int prev_alpha_numeric(const string& s, int index){
        for(int i = index ; i >= 0 ; i --)
            if(isalnum(s[i]))
                return i;
        return -1;
    }
};


void print_bool(bool res){
    cout << (res ? "True" : "False") << endl;
}

int main() {

    string s1 = "A man, a plan, a canal: Panama";
    print_bool(Solution().isPalindrome(s1));

    string s2 = "race a car";
    print_bool(Solution().isPalindrome(s2));

    return 0;
}