/// Source : https://leetcode.com/problems/long-pressed-name/
/// Author : liuyubobobo
/// Time   : 2018-10-21

#include <iostream>
#include <vector>

using namespace std;


/// Split the name and typed by characters
/// Time Complexity: O(len(typed) + len(name))
/// Space Complexity: O(max(len(typed), len(name)))
class Solution {

public:
    bool isLongPressedName(string name, string typed) {

        vector<pair<char, int>> chars1 = split(name);
        vector<pair<char, int>> chars2 = split(typed);
        if(chars1.size() != chars2.size())
            return false;

        for(int i = 0; i < chars1.size(); i ++)
            if(chars1[i] > chars2[i])
                return false;
        return true;
    }

private:
    vector<pair<char, int>> split(const string& s){

        vector<pair<char, int>> res;
        int start = 0;
        for(int i = start + 1; i <= s.size(); i ++)
            if(i == s.size() || s[i] != s[start]){
                res.push_back(make_pair(s[start], i - start));
                start = i;
            }
        return res;
    }
};


int main() {

    cout << Solution().isLongPressedName("alex", "aaleex") << endl;
    // true

    cout << Solution().isLongPressedName("saeed", "ssaaedd") << endl;
    // false

    cout << Solution().isLongPressedName("leelee", "lleeelee") << endl;
    // true

    cout << Solution().isLongPressedName("laiden", "laiden") << endl;
    // true

    return 0;
}