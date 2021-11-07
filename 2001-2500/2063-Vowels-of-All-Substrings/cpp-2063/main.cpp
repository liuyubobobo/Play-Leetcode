/// Source : https://leetcode.com/problems/vowels-of-all-substrings/
/// Author : liuyubobobo
/// Time   : 2021-11-06

#include <iostream>

using namespace std;


/// Mathematics
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    long long countVowels(string word) {

        int n = word.size();
        long long res = 0;
        for(int i = 0; i < n; i ++)
            if(is_vowel(word[i]))
                res += (long long)(i + 1) * (n - i);
        return res;
    }

private:
    bool is_vowel(char c){
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};


int main() {

    cout << Solution().countVowels("aba") << endl;
    // 6

    cout << Solution().countVowels("abc") << endl;
    // 3

    cout << Solution().countVowels("ltcd") << endl;
    // 0

    return 0;
}
