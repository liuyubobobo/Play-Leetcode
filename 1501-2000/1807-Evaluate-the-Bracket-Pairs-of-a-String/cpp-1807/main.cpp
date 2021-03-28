/// Source : https://leetcode.com/problems/evaluate-the-bracket-pairs-of-a-string/
/// Author : liuyubobobo
/// Time   : 2021-03-27

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


/// Linear Scan + Using HashMap
/// Time Complexity: O(|s|)
/// Space Complexity: O(|knowledge|)
class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {

        unordered_map<string, string> map;
        for(const vector<string>& p: knowledge)
            map[p[0]] = p[1];

        string res = "", key = "";
        for(char c: s)
            if(c == '(') key += c;
            else if(c == ')'){
                key = key.substr(1);
//                cout << key << endl;
                res += (map.count(key) ? map[key] : "?");
                key = "";
            }
            else{
                if(key.empty()) res += c;
                else key += c;
            }
        return res;
    }
};


int main() {

    vector<vector<string>> knowledge1 = {{"name","bob"},{"age","two"}};
    cout << Solution().evaluate("(name)is(age)yearsold", knowledge1) << endl;
    // bobistwoyearsold

    vector<vector<string>> knowledge2 = {{"a","b"}};
    cout << Solution().evaluate("hi(name)", knowledge2) << endl;
    // hi?

    vector<vector<string>> knowledge3 = {{"a","yes"}};
    cout << Solution().evaluate("(a)(a)(a)aaa", knowledge3) << endl;
    // yesyesyesaaa

    vector<vector<string>> knowledge4 = {{"a","b"}, {"b", "a"}};
    cout << Solution().evaluate("(a)(b)", knowledge4) << endl;
    // ba

    return 0;
}
