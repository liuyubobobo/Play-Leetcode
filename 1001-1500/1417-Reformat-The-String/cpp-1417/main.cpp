/// Source : https://leetcode.com/problems/reformat-the-string/
/// Author : liuyubobobo
/// Time   : 2020-04-18

#include <iostream>
#include <vector>

using namespace std;


/// Ad-Hoc
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    string reformat(string s) {

        string a, b;
        for(char c: s)
            if(c >= '0' && c <= '9') a += c;
            else b += c;

        if(abs((int)a.size() - (int)b.size()) >= 2) return "";

        if(a.size() < b.size()) swap(a, b);
        string res = "";
        for(int i = 0; i < b.size(); i ++){
            res += a[i];
            res += b[i];
        }

        if(a.size() > b.size()) res += a.back();
        return res;
    }
};


int main() {

    cout << Solution().reformat("covid2019") << endl;

    return 0;
}
