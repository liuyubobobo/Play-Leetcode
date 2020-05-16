/// Source : https://leetcode.com/problems/consecutive-characters/
/// Author : liuyubobobo
/// Time   : 2020-05-16

#include <iostream>

using namespace std;


/// Linear Scan
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int maxPower(string s) {

        int res = 0;
        for(int start = 0, i = 1; i <= s.size(); i ++)
            if(i == s.size() || s[i] != s[start]){
                res = max(res, i - start);
                start = i;
                i = start;
            }
        return res;
    }
};


int main() {

    return 0;
}
