/// Source : https://leetcode.com/problems/is-subsequence/
/// Author : liuyubobobo
/// Time   : 2019-08-04

#include <iostream>

using namespace std;


/// Simulation
/// Time Complexity: O(len(s) + len(t))
/// Space Complexity: O(1)
class Solution {
public:
    bool isSubsequence(string s, string t) {

        int index = -1;
        for(char c: s){
            index = t.find(c, index + 1);
            if(index == string::npos) return false;
        }
        return true;
    }
};


int main() {

    return 0;
}