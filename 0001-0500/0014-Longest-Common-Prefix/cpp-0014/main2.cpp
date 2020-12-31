/// Source : https://leetcode.com/problems/longest-common-prefix/description/
/// Author : liuyubobobo
/// Time   : 2018-06-03

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;


/// Horizonal Scan
/// Time Complexity: O(len(strs) * max len of string)
/// Space Complexity: O(1)
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        if(strs.size() == 0)
            return "";

        string res = strs[0];

        for(int i = 1 ; i < strs.size() ; i ++){
            for(int j = 0 ; j < res.size() ; j ++)
                if(j >= strs[i].size() || res[j] != strs[i][j]){
                    res = res.substr(0, j);
                    break;
                }
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