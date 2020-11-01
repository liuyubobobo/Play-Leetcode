/// Source : https://leetcode.com/problems/count-substrings-that-differ-by-one-character/
/// Author : liuyubobobo
/// Time   : 2020-11-01

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;


/// Dynamic Programming with Space Optimization
/// Time Complexity: O(|s| * |t|)
/// Space Complexity: O(|s| * |t|)
class Solution {
public:
    int countSubstrings(string s, string t) {

        int res = 0, same, diff1;
        for(int j = 0; j < t.size(); j ++){
            int curi = 0, curj = j;
            same = s[curi] == t[curj] ? 1 : 0;
            diff1 = 1 - same;
            res += diff1;
            while(curi + 1 < s.size() && curj + 1 < t.size()){
                curi ++, curj ++;
                diff1 = s[curi] == t[curj] ? diff1 : (same + 1);
                same = s[curi] == t[curj] ? same + 1 : 0;
                res += diff1;
            }
        }

        for(int i = 1; i < s.size(); i ++){
            int curi = i, curj = 0;
            same = s[curi] == t[curj] ? 1 : 0;
            diff1 = 1 - same;
            res += diff1;
            while(curi + 1 < s.size() && curj + 1 < t.size()){
                curi ++, curj ++;
                diff1 = s[curi] == t[curj] ? diff1 : (same + 1);
                same = s[curi] == t[curj] ? same + 1 : 0;
                res += diff1;
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

    cout << Solution().countSubstrings("abbab", "bbbbb") << endl;
    // 33

    return 0;
}
