/// Source : https://leetcode.com/problems/longest-nice-substring/
/// Author : liuyubobobo
/// Time   : 2021-02-20

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force with Optimization
/// Time Complexity: O(n^2)
/// Space Complexity: O(1)
class Solution {
public:
    string longestNiceSubstring(string s) {

        string res = "";
        for(int i = 0; i < s.size(); i ++){
            vector<bool> lower(26, false), upper(26, false);
            for(int j = i; j < s.size(); j ++){
                if(islower(s[j])) lower[s[j] - 'a'] = true;
                else upper[s[j] - 'A'] = true;

                if((lower == upper) && (j - i + 1) > (int)res.size())
                    res = s.substr(i, j - i + 1);
            }
        }
        return res;
    }
};


int main() {

    return 0;
}
