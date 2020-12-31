/// Source : https://leetcode.com/problems/longest-common-prefix/description/
/// Author : liuyubobobo
/// Time   : 2018-06-03

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;


/// Divide and Conquer
/// Time Complexity: O(len(strs) * max len of string)
/// Space Complexity: O(log(len(strs)))
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        if(strs.size() == 0)
            return "";

        return solve(strs, 0, strs.size() - 1);
    }

private:
    string solve(const vector<string>& strs, int start, int end){

        if(start == end)
            return strs[start];

        int mid = (start + end) / 2;
        string res1 = solve(strs, start, mid);
        string res2 = solve(strs, mid + 1, end);

        int i = 0;
        for( ; i < res1.size() && i < res2.size(); i ++)
            if(res1[i] != res2[i])
                break;

        return res1.substr(0, i);
    }
};


int main() {

    vector<string> strs1 = {"flower","flow","flight"};
    cout << Solution().longestCommonPrefix(strs1) << endl;

    vector<string> strs2 = {"dog","racecar","car"};
    cout << Solution().longestCommonPrefix(strs2) << endl;

    return 0;
}