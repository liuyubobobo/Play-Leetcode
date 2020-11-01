/// Source : https://leetcode.com/problems/count-substrings-that-differ-by-one-character/
/// Author : liuyubobobo
/// Time   : 2020-10-31

#include <iostream>
#include <unordered_map>

using namespace std;


/// Brute Force
/// Time Complexity: O(|s| * |t| * min(|s|, |t|))
/// Space Complexity: O(1)
class Solution {
public:
    int countSubstrings(string s, string t) {

        int res = 0;
        for(int i = 0; i < s.size(); i ++)
            for(int j = 0; j < t.size(); j ++){
                int diff = 0;
                for(int len = 0; i + len < s.size() && j + len < t.size(); len ++){
                    diff += s[i + len] != t[j + len];
                    if(diff == 1) res ++;
                    else if(diff > 1) break;
                }
            }
        return res;
    }
};


int main() {

    cout << Solution().countSubstrings("aba", "baba") << endl;
    // 6

    cout << Solution().countSubstrings("ab", "bb") << endl;
    // 3

    cout << Solution().countSubstrings("a", "a") << endl;
    // 0

    cout << Solution().countSubstrings("abe", "bbc") << endl;
    // 10

    return 0;
}
