/// Source : https://leetcode-cn.com/problems/minimum-deletions-to-make-string-balanced/
/// Author : liuyubobobo
/// Time   : 2020-11-14

#include <iostream>
#include <vector>

using namespace std;


/// Presum + Postsum
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int minimumDeletions(string s) {

        int n = s.size();

        vector<int> preb(n + 1, 0);
        for(int i = 0; i < n; i ++)
            preb[i + 1] = preb[i] + (s[i] == 'b');

        vector<int> posta(n + 1, 0);
        for(int i = n - 1; i >= 0; i --)
            posta[i] = posta[i + 1] + (s[i] == 'a');

        int res = min(preb[n], posta[0]);
        for(int i = 0; i < n; i ++)
            res = min(res, posta[i] + preb[i]);
        return res;
    }
};


int main() {

    cout << Solution().minimumDeletions("aababbab") << endl;
    // 2

    cout << Solution().minimumDeletions("a") << endl;
    // 0

    cout << Solution().minimumDeletions("aabbbbaabababbbbaaaaaabbababaaabaabaabbbabbbbabbabbababaabaababbbbaaaaabbabbabaaaabbbabaaaabbaaabbbaabbaaaaabaa") << endl;
    // 52

    return 0;
}
