/// Source : https://leetcode.com/problems/truncate-sentence/
/// Author : liuyubobobo
/// Time   : 2021-04-03

#include <iostream>
#include <vector>

using namespace std;


/// Linear Scan
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    string truncateSentence(string s, int k) {

        string res = "";
        for(int start = 0, i = start + 1; i <= s.size() && k; i ++)
            if(i == s.size() || s[i] == ' '){
                res += s.substr(start, i - start) + " ";
                start = i + 1;
                i = start;
                k --;
            }

        res.pop_back();
        return res;
    }
};


int main() {

    return 0;
}
