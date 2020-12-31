/// Source : https://leetcode.com/problems/maximum-nesting-depth-of-two-valid-parentheses-strings/
/// Author : liuyubobobo
/// Time   : 2019-07-07

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;


/// Alternatively Assign 0 and 1
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    vector<int> maxDepthAfterSplit(string s) {

        vector<int> res(s.size(), 0);

        int stack = 0;
        for(int i = 0; i < s.size(); i ++)
            if(s[i] == '(') stack ++, res[i] = stack % 2;
            else res[i] = stack % 2, stack --;
        return res;
    }
};


int main() {

    return 0;
}