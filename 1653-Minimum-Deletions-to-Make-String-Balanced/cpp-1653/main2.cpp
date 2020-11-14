/// Source : https://leetcode-cn.com/problems/minimum-deletions-to-make-string-balanced/
/// Author : liuyubobobo
/// Time   : 2020-11-14

#include <iostream>
#include <vector>

using namespace std;


/// Postsum
/// Space Optimization with Solution1
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int minimumDeletions(string s) {

        int n = s.size();

        vector<int> posta(n + 1, 0);
        for(int i = n - 1; i >= 0; i --)
            posta[i] = posta[i + 1] + (s[i] == 'a');

        int res = posta[0], b = 0;
        for(int i = 0; i < n; i ++){
            b += s[i] == 'b';
            res = min(res, b + posta[i + 1]);
        }
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
