/// Source : https://leetcode.com/problems/adding-spaces-to-a-string/
/// Author : liuyubobobo
/// Time   : 2021-12-18

#include <iostream>
#include <vector>

using namespace std;


/// Simulation
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {

        string res = "";
        for(int i = 0, p = 0; i < s.size(); i ++){
            if(p < spaces.size() && i == spaces[p])
                res += (char)(' '), p ++;
            res += s[i];
        }
        return res;
    }
};


int main() {

    return 0;
}
