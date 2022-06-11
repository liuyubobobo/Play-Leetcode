/// Source : https://leetcode.com/problems/match-substring-after-replacement/
/// Author : liuyubobobo
/// Time   : 2022-06-11

#include <iostream>
#include <vector>

using namespace std;


/// Using Map Table
/// Time Complexity: O(n * m)
/// Space Complexity: O(1)
class Solution {
public:
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {

        vector<vector<bool>> map_table(256, vector<bool>(256, false));
        for(const vector<char>& mapping: mappings){
            char old_ch = mapping[0], new_ch = mapping[1];
            map_table[old_ch][new_ch] = true;
        }

        for(int i = 0; i + sub.size() <= s.size(); i ++){

            bool ok = true;
            for(int j = 0; j < sub.size() && ok; j ++)
                ok = sub[j] == s[i + j] || map_table[sub[j]][s[i + j]];
            if(ok) return true;
        }
        return false;
    }
};


int main() {

    return 0;
}
