/// Source : https://leetcode.com/problems/maximum-nesting-depth-of-two-valid-parentheses-strings/
/// Author : liuyubobobo
/// Time   : 2019-07-06

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;


/// Halve max depth
/// Time Complexity: O(2n)
/// Space Complexity: O(1)
class Solution {
public:
    vector<int> maxDepthAfterSplit(string s) {

        int bound = get_depth(s) / 2;

        vector<int> res(s.size(), 0);
        int stack = 0;
        for(int i = 0; i < s.size(); i ++){
            if(s[i] == '(') stack ++, res[i] = (stack > bound);
            else res[i] = (stack > bound), stack --;

        }
        return res;
    }

private:
    int get_depth(const string& s){

        int res = 0, stack = 0;
        for(char c: s)
            if(c == '(') stack ++, res = max(res, stack);
            else stack --;
        assert(!stack);
        return res;
    }
};


int main() {

    return 0;
}