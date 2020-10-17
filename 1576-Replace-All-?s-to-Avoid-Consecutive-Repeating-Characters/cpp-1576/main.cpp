/// Source : https://leetcode.com/problems/replace-all-s-to-avoid-consecutive-repeating-characters/
/// Author : liuyubobobo
/// Time   : 2020-09-05

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    string modifyString(string s) {

        for(int i = 0; i < s.size(); i ++)
            if(s[i] == '?')
                s[i] = replace(s, i);
        return s;
    }

private:
    char replace(const string& s, int i){

        for(char c = 'a'; c <= 'z'; c ++){
            if(i - 1 >= 0 && s[i - 1] == c) continue;
            if(i + 1 < s.size() && s[i + 1] == c) continue;
            return c;
        }
//        assert(false);
        return 'z';
    }
};


int main() {

    cout << Solution().modifyString("?zs") << endl;
    // azs

    cout << Solution().modifyString("ubv?w") << endl;
    // ubvaw

    cout << Solution().modifyString("j?qg??b") << endl;
    // jaqgacb

    cout << Solution().modifyString("??yw?ipkj?") << endl;
    // jaqgacb

    return 0;
}
