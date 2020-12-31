/// Source : https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/
/// Author : liuyubobobo
/// Time   : 2020-11-07

#include <iostream>
#include <vector>
#include <map>

using namespace std;


/// Greedy
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int minDeletions(string s) {

        vector<int> f(26, 0);
        for(char c: s) f[c - 'a'] ++;

        sort(f.begin(), f.end(), greater<int>());

        int res = 0;
        for(int i = 1; i < 26; i ++)
            if(f[i] && f[i] >= f[i - 1]){
                int a = max(f[i - 1] - 1, 0);
                res += f[i] - a, f[i] = a;
            }
        return res;
    }
};


int main() {

    cout << Solution().minDeletions("aab") << endl;
    // 0

    cout << Solution().minDeletions("aaabbbcc") << endl;
    // 2

    cout << Solution().minDeletions("ceabaacb") << endl;
    // 2

    cout << Solution().minDeletions("bbcebab") << endl;
    // 2

    return 0;
}
