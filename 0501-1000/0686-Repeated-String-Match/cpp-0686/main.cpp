/// Source : https://leetcode.com/problems/repeated-string-match/
/// Author : liuyubobobo
/// Time   : 2021-12-21

#include <iostream>
#include <vector>

using namespace std;


/// Ad-Hoc
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int repeatedStringMatch(string a, string b) {

        string s = "";
        int t = 0;
        while(s.size() < b.size()) s += a, t ++;

        if(s.find(b) != string::npos) return t;
        s += a, t ++;
        if(s.find(b) != string::npos) return t;

        return -1;
    }
};


int main() {

    return 0;
}
