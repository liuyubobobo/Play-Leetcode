/// Source : https://leetcode.com/problems/isomorphic-strings/description/
/// Author : liuyubobobo
/// Time   : 2018-06-01

#include <iostream>

using namespace std;

/// Mapping
/// Time Complexity: O(len(s))
/// Space Complexity: O(len of charset)
class Solution {
public:
    bool isIsomorphic(string s, string t) {

        if(s.size() != t.size())
            return false;

        int map[256];
        memset(map, -1, sizeof(map));

        bool mapped[256];
        memset(mapped, false, sizeof(mapped));

        for(int i = 0 ; i < s.size() ; i ++){
            if(map[s[i]] == -1){
                if(mapped[t[i]])
                    return false;
                map[s[i]] = t[i];
                mapped[t[i]] = true;
            }
            else if(map[s[i]] != t[i])
                return false;
        }
        return true;
    }
};


void print_bool(bool res){
    cout << (res ? "True" : "False") << endl;
}

int main() {

    print_bool(Solution().isIsomorphic("egg", "add"));
    print_bool(Solution().isIsomorphic("foo", "bar"));
    print_bool(Solution().isIsomorphic("paper", "title"));
    print_bool(Solution().isIsomorphic("aa", "ab"));

    return 0;
}