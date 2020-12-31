/// Source : https://leetcode.com/problems/longest-common-prefix/description/
/// Author : liuyubobobo
/// Time   : 2018-06-03

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;


/// Vertical Scan
/// Time Complexity: O(len(strs) * max len of string)
/// Space Complexity: O(1)
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        string res = "";
        if(strs.size() == 0)
            return res;

        for(int i = 0 ; i < strs[0].size() ; i ++){

            char c = strs[0][i];
            for(int j = 1 ; j < strs.size() ; j ++)
                if(i >= strs[j].size() || strs[j][i] != c)
                    return res;

            res += c;
        }

        return res;
    }
};


int main() {

    vector<string> strs1 = {"flower","flow","flight"};
    cout << Solution().longestCommonPrefix(strs1) << endl;

    vector<string> strs2 = {"dog","racecar","car"};
    cout << Solution().longestCommonPrefix(strs2) << endl;

    return 0;
}