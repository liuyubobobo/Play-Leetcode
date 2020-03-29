/// Source : https://leetcode.com/problems/longest-happy-prefix/
/// Author : liuyubobobo
/// Time   : 2020-03-29

#include <iostream>
#include <vector>

using namespace std;


/// Rolling Hash
/// Not very convincing that it's 100% correct
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {

private:
    long long MOD = 1e9 + 7;

public:
    string longestPrefix(string s) {

        int n = s.size();
        long long pre_hash = 0, post_hash = 0, pow26 = 1ll;
        int reslen = 0;
        for(int i = 0; i + 1 < n; i ++){
            pre_hash = (pre_hash * 26 + (s[i] - 'a')) % MOD;
            post_hash = ((s[n - i - 1] - 'a') * pow26 + post_hash) % MOD;
            pow26 = pow26 * 26ll % MOD;
            if(pre_hash == post_hash /*&& s.substr(0, i + 1) == s.substr(n - i - 1)*/)
                reslen = i + 1;
        }
        return s.substr(0, reslen);
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
