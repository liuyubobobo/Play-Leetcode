/// Source : https://leetcode.com/problems/count-the-number-of-vowel-strings-in-range/description/
/// Author : liuyubobobo
/// Time   : 2023-03-13

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int vowelStrings(vector<string>& words, int left, int right) {

        int res = 0;
        for(int i = left; i <= right; i ++)
            res += check(words[i]);
        return res;
    }

private:
    bool check(const string& s){
        return is_vowel(s[0]) && is_vowel(s.back());
    }

    bool is_vowel(char c){
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};


int main() {

    return 0;
}
