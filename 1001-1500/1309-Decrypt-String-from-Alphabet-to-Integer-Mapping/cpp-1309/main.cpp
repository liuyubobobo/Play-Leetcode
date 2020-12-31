/// Source : https://leetcode.com/problems/decrypt-string-from-alphabet-to-integer-mapping/
/// Author : liuyubobobo
/// Time   : 2020-01-04

#include <iostream>

using namespace std;


/// Linear Scan
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    string freqAlphabets(string s) {

        string res = "";
        for(int i = 0; i < s.size();)
            if(s[i] <= '2' && i + 2 < s.size() && s[i + 2] == '#'){
                res += (s[i] - '0') * 10 + (s[i + 1] - '0') - 1 + 'a';
                i += 3;
            }
            else{
                res += (s[i] - '0') - 1 + 'a';
                i ++;
            }
        return res;
    }
};


int main() {

    cout << Solution().freqAlphabets("10#11#12") << endl;
    // jkab

    cout << Solution().freqAlphabets("1326#") << endl;
    // acz

    cout << Solution().freqAlphabets("25#") << endl;
    // y

    return 0;
}
