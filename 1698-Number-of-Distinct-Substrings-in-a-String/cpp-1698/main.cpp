/// Source : https://leetcode-cn.com/problems/number-of-distinct-substrings-in-a-string/
/// Author : liuyubobobo
/// Time   : 2020-12-26

#include <iostream>
#include <map>
#include <vector>

using namespace std;


/// Trie
/// Time Complexity: O(n^2)
/// Space Complexity: O(n^2)
class Solution {

private:
    int trie[125250][26];

public:
    int countDistinct(string s) {

        memset(trie, -1, sizeof(trie));

        int sz = 1, res = 0;
        for(int i = 0; i < s.size(); i ++){
            int cur = 0;
            for(int j = i; j < s.size(); j ++){
                if(trie[cur][s[j] - 'a'] == -1){
                    trie[cur][s[j] - 'a'] = sz ++;
                    res ++;
                }
                cur = trie[cur][s[j] - 'a'];
            }
        }
        return res;
    }
};


int main() {

    return 0;
}
