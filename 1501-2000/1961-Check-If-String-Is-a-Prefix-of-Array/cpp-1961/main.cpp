/// Source : https://leetcode.com/problems/check-if-string-is-a-prefix-of-array/
/// Author : liuyubobobo
/// Time   : 2021-08-09

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {

        string cur = "";
        for(const string& e: words){
            cur += e;
            if(s == cur) return true;
        }
        return false;
    }
};


int main() {

    return 0;
}
