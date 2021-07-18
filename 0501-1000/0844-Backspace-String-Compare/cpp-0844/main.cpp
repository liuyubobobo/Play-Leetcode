/// Source : https://leetcode.com/problems/backspace-string-compare/
/// Author : liuyubobobo
/// Time   : 2021-07-17

#include <iostream>

using namespace std;


/// Simulation
/// Time Complexity: O(|s| + |t|)
/// Space Complexity: O(1)
class Solution {
public:
    bool backspaceCompare(string s, string t) {

        string a = get_input(s), b = get_input(t);
        return a == b;
    }

private:
    string get_input(const string& s){

        string res = "";
        for(char c: s)
            if(c != '#') res += c;
            else if(res.size()) res.pop_back();
        return res;
    }
};


int main() {

    return 0;
}
