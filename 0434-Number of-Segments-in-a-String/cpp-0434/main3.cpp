/// Source : https://leetcode.com/problems/number-of-segments-in-a-string/description/
/// Author : liuyubobobo
/// Time   : 2017-11-04

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

/// Just count the segment number
///
/// Time Complexity: O(len(s))
/// Space Complexity: O(1)
class Solution {
public:
    int countSegments(string s) {

        int startIndex = 0;
        while(startIndex < s.size() && s[startIndex] == ' ')
            startIndex ++;

        int res = 0;
        for(int i = startIndex + 1 ; i <= s.size() ; i ++)
            if((i == s.size() && s[i-1] != ' ') ||
                    s[i] != ' ' && s[i-1] == ' ')
                res ++;

        return res;
    }
};

int main() {

    cout << Solution().countSegments("Hello, my name is John") << endl;

    return 0;
}