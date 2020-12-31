/// Source : https://leetcode.com/problems/number-of-segments-in-a-string/description/
/// Author : liuyubobobo
/// Time   : 2017-11-04

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

/// Special for C++
/// Using sstream
///
/// Time Complexity: O(len(s))
/// Space Complexity: O(len(s))
class Solution {
public:
    int countSegments(string s) {

        stringstream ss(s);
        string str;
        int res = 0;
        while(ss >> str)
            res ++;

        return res;
    }
};

int main() {

    cout << Solution().countSegments("Hello, my name is John") << endl;

    return 0;
}