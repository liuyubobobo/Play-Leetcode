/// Source : https://leetcode-cn.com/problems/minimum-deletions-to-make-string-balanced/
/// Author : liuyubobobo
/// Time   : 2020-11-14

#include <iostream>
#include <vector>

using namespace std;


/// Dynamic Programming
/// a: ending with a, b: ending with b
/// Space Optimization with Solution3
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int minimumDeletions(string s) {

        int a = 0, b = 0;
        for(char c: s){
            if(c == 'a') b ++;
            else b = min(a, b), a ++;
        }
        return min(a, b);
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
