/// Source : https://leetcode.com/problems/license-key-formatting/
/// Author : liuyubobobo
/// Time   : 2021-10-03

#include <iostream>

using namespace std;


/// String
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    string licenseKeyFormatting(string s, int k) {

        string t = "";
        for(char c: s)
            if(c != '-') t += toupper(c);

        reverse(t.begin(), t.end());
        string res = t.substr(0, k);
        for(int i = k; i < t.size(); i += k)
            res += "-" + t.substr(i, k);
        reverse(res.begin(), res.end());
        return res;
    }
};


int main() {

    cout << Solution().licenseKeyFormatting("5F3Z-2e-9-w", 4) << endl;
    // "5F3Z-2E9W"

    return 0;
}
