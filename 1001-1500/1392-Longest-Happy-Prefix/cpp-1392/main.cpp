/// Source : https://leetcode.com/problems/longest-happy-prefix/
/// Author : liuyubobobo
/// Time   : 2020-03-21

#include <iostream>
#include <vector>

using namespace std;


/// KMP-based method
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    string longestPrefix(string s) {

        int n = s.size();
        vector<int> lps(n, 0);

        int len = 0;
        for(int i = 1; i < n; i ++){
            while(len && s[i] != s[len])
                len = lps[len - 1];

            if(s[i] == s[len])
                lps[i] = ++ len;
        }

        return s.substr(0, lps.back());
    }
};


int main() {

    cout << Solution().longestPrefix("level") << endl;
    // l

    cout << Solution().longestPrefix("ababab") << endl;
    // abab

    cout << Solution().longestPrefix("leetcodeleet") << endl;
    // leet

    cout << Solution().longestPrefix("a") << endl;
    // empty

    return 0;
}
