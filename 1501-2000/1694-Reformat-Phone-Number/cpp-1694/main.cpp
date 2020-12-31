/// Source : https://leetcode.com/problems/reformat-phone-number/
/// Author : liuyubobobo
/// Time   : 2020-12-19

#include <iostream>
#include <vector>

using namespace std;


/// Split
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    string reformatNumber(string number) {

        string s = "";
        for(char c: number)
            if(isdigit(c)) s += c;

        vector<string> v;
        while(s.size() > 4){
            v.push_back(s.substr(0, 3));
            s = s.substr(3);
        }
        if(s.size() == 4)
            v.push_back({s.substr(0, 2)}),
            v.push_back({s.substr(2)});
        else
            v.push_back(s);

        string res = v[0];
        for(int i = 1; i < v.size(); i ++)
            res += "-" + v[i];
        return res;
    }
};


int main() {

    return 0;
}
