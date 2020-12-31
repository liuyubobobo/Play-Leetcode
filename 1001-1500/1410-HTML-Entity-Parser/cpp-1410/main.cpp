/// Source : https://leetcode.com/problems/html-entity-parser/
/// Author : liuyubobobo
/// Time   : 2020-04-11

#include <iostream>

using namespace std;


/// Brute Force
/// Time Complexity: O(|text|)
/// Space Complexity: O(|text|)
class Solution {
public:
    string entityParser(string text) {

        string res = "";
        for(int i = 0; i < text.size(); )
            if(text[i] == '&'){
                if(i + 5 < text.size() && text.substr(i, 6) == "&quot;")
                    res += '"', i += 6;
                else if(i + 5 < text.size() && text.substr(i, 6) == "&apos;")
                    res += '\'', i += 6;
                else if(i + 4 < text.size() && text.substr(i, 5) == "&amp;")
                    res += '&', i += 5;
                else if(i + 3 < text.size() && text.substr(i, 4) == "&gt;")
                    res += '>', i += 4;
                else if(i + 3 < text.size() && text.substr(i, 4) == "&lt;")
                    res += '<', i += 4;
                else if(i + 6 < text.size() && text.substr(i, 7) == "&frasl;")
                    res += '/', i += 7;
                else res += text[i], i ++;
            }
            else res += text[i], i ++;
        return res;
    }
};


int main() {

    cout << Solution().entityParser("&amp; is an HTML entity but &ambassador; is not.") << endl;

    return 0;
}
