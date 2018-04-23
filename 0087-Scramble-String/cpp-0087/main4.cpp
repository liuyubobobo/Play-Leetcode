/// Source : https://leetcode.com/problems/scramble-string/description/
/// Author : liuyubobobo
/// Time   : 2018-04-23

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

/// Dynamic Programming
/// Time Complexity: O(n^4)
/// Space Complexity: O(n^3)
class Solution {

public:
    bool isScramble(string s1, string s2) {

        if(s1.size() != s2.size())
            return false;

        vector<vector<vector<bool>>> memo(s1.size() + 1,
                                         vector<vector<bool>>(s1.size(), vector<bool>(s2.size(), false))
        );
        for(int i = 0 ; i < s1.size() ; i ++)
            for(int j = 0 ; j < s2.size() ; j ++)
                if(s1[i] == s2[j])
                    memo[1][i][j] = true;

        for(int len = 2 ; len <= s1.size() ; len ++)
            for(int i1 = 0 ; i1 <= s1.size() - len ; i1 ++)
                for(int i2 = 0 ; i2 <= s2.size() - len ; i2 ++){

                    for(int i = 1 ; i <= len - 1 ; i ++){
                        if(memo[i][i1][i2] && memo[len - i][i1 + i][i2 + i]){
                            memo[len][i1][i2] = true;
                            break;
                        }
                        else if(memo[i][i1][i2 + len - i] && memo[len - i][i1 + i][i2]){
                            memo[len][i1][i2] = true;
                            break;
                        }
                    }
                }

        return memo[s1.size()][0][0];
    }

};


void print_bool(bool res){
    cout << (res ? "true" : "false") << endl;
}

int main() {

    print_bool(Solution().isScramble("great", "rgeat"));
    print_bool(Solution().isScramble("abcde", "caebd"));
    print_bool(Solution().isScramble("abcdefghijklmn", "efghijklmncadb"));
    print_bool(Solution().isScramble("abc", "bca"));

    return 0;
}