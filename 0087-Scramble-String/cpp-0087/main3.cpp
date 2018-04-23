/// Source : https://leetcode.com/problems/scramble-string/description/
/// Author : liuyubobobo
/// Time   : 2018-04-23

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

/// Memory Search
/// Time Complexity: O(n^4)
/// Space Complexity: O(n^4)
class Solution {

public:
    bool isScramble(string s1, string s2) {

        if(s1.size() != s2.size())
            return false;

        vector<vector<vector<int>>> memo(s1.size() + 1,
                vector<vector<int>>(s1.size(), vector<int>(s2.size(), -1))
            );
        return isScramble(s1, s2, s1.size(), 0, 0, memo);
    }

private:
    bool isScramble(string s1, string s2, int len, int i1, int i2,
                    vector<vector<vector<int>>>& memo) {

        if(memo[len][i1][i2] != -1)
            return memo[len][i1][i2];

        string a = s1.substr(i1, len);
        string b = s2.substr(i2, len);
        if(a == b)
            return memo[len][i1][i2] = true;

        unordered_map<char, int> freq;
        for(char c: a)
            freq[c] += 1;
        for(char c: b)
            if(freq.find(c) == freq.end())
                return memo[len][i1][i2] = false;
            else{
                freq[c] -= 1;
                if(freq[c] == 0)
                    freq.erase(c);
            }

        for(int i = 1 ; i <= len - 1 ; i ++){
            if(isScramble(s1, s2, i, i1, i2, memo)
               && isScramble(s1, s2, len - i, i1 + i, i2 + i, memo))
                return memo[len][i1][i2] = true;
            if(isScramble(s1, s2, i, i1, i2 + len - i, memo)
               && isScramble(s1, s2, len - i, i1 + i, i2, memo))
                return memo[len][i1][i2] = true;
        }

        return memo[len][i1][i2] = false;
    }
};


void print_bool(bool res){
    cout << (res ? "true" : "false") << endl;
}

int main() {

    print_bool(Solution().isScramble("great", "rgeat"));
    print_bool(Solution().isScramble("abcde", "caebd"));
    print_bool(Solution().isScramble("abcdefghijklmn", "efghijklmncadb"));

    return 0;
}