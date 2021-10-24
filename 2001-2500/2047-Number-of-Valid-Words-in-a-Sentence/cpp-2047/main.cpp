/// Source : https://leetcode.com/problems/number-of-valid-words-in-a-sentence/
/// Author : liuyubobobo
/// Time   : 2021-10-23

#include <iostream>
#include <vector>

using namespace std;


/// Simulation
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int countValidWords(string s) {

        int res = 0;
        for(int start = next_non_space(s, 0), i = start + 1; i <= s.size(); i ++)
            if(i == s.size() || s[i] == ' '){
                string word = s.substr(start, i - start);
                res += check(word);

                start = next_non_space(s, i);
                i = start;
            }
        return res;
    }

private:
    bool check(const string& s){

        for(char c: s) if(isdigit(c)) return false;

        int hyphen = -1;
        for(int i = 0; i < s.size(); i ++)
            if(s[i] == '-'){
                if(hyphen != -1) return false;
                hyphen = i;
            }
        if(hyphen != -1) {
            if (hyphen == 0 || hyphen == s.size() - 1) return false;
            if (!islower(s[hyphen - 1])) return false;
            if (!islower(s[hyphen + 1])) return false;
        }

        int dot = -1;
        for(int i = 0; i < s.size(); i ++)
            if(s[i] == '!' || s[i] == '.' || s[i] == ','){
                if(dot != -1) return false;
                dot = i;
            }
        return dot == -1 || dot == s.size() - 1;
    }

    int next_non_space(const string& s, int start){

        for(int i = start; i < s.size(); i ++)
            if(s[i] != ' ') return i;
        return s.size();
    }
};


int main() {

    cout << Solution().countValidWords("cat and  dog") << endl;
    // 3

    cout << Solution().countValidWords("!this  1-s b8d!") << endl;
    // 0

    cout << Solution().countValidWords("alice and  bob are playing stone-game10") << endl;
    // 5

    cout << Solution().countValidWords("he bought 2 pencils, 3 erasers, and 1  pencil-sharpener.") << endl;
    // 6

    return 0;
}
