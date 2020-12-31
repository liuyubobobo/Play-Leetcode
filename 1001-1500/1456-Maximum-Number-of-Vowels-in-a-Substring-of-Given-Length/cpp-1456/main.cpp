/// Source : https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/
/// Author : liuyubobobo
/// Time   : 2020-05-23

#include <iostream>

using namespace std;


/// Sliding Window
/// Time Complexity: O(|s|)
/// Space Complexity: O(1)
class Solution {
public:
    int maxVowels(string s, int k) {

        int res = 0, cur = 0;
        for(int i = 0; i < k - 1 && i < s.size(); i ++)
            cur += is_vowel(s[i]);

        for(int i = k - 1; i < s.size(); i ++){
            cur += is_vowel(s[i]);
            res = max(res, cur);
            cur -= is_vowel(s[i - (k - 1)]);
        }
        return res;
    }

private:
    bool is_vowel(char c){
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};


int main() {

    cout << Solution().maxVowels("abciiidef", 3) << endl;
    // 3

    cout << Solution().maxVowels("aeiou", 2) << endl;
    // 2

    cout << Solution().maxVowels("leetcode", 3) << endl;
    // 2

    cout << Solution().maxVowels("rhythms", 4) << endl;
    // 0

    cout << Solution().maxVowels("tryhard", 4) << endl;
    // 1

    return 0;
}
