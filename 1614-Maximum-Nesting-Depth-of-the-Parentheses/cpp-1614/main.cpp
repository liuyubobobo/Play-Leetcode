/// Source : https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/
/// Author : liuyubobobo
/// Time   : 2020-10-10

#include <iostream>
#include <string>

using namespace std;


/// Stack Simulation
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int maxDepth(string s) {

        int res = 0, stack = 0;
        for(char c: s){
            if(c == '(') stack ++;
            else if(c == ')') stack --;
            res = max(res, stack);
        }
        return res;
    }
};


int main() {

    return 0;
}
