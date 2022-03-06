/// Source : https://leetcode.com/problems/minimum-number-of-moves-to-make-palindrome/
/// Author : liuyubobobo
/// Time   : 2022-03-06

#include <iostream>

using namespace std;


/// Greedy
/// Time Complexity: O(n^2)
/// Space Complexity: O(n)
class Solution {
public:
    int minMovesToMakePalindrome(string s) {

        return dfs(s, 0, s.size() - 1);
    }

private:
    int dfs(string& s, int l, int r){

        if(l >= r) return 0;
        if(s[l] == s[r]) return dfs(s, l + 1, r - 1);

        int front_pos, tail_pos, front_swaps = 0, tail_swaps = 0;
        for(front_pos = l; front_pos <= r && s[front_pos] != s[r]; front_pos ++, front_swaps ++);
        for(tail_pos = r; tail_pos >= l && s[tail_pos] != s[l]; tail_pos --, tail_swaps ++);


        if(front_swaps <= tail_swaps){
            for(int i = front_pos - 1; i >= l; i --) swap(s[i], s[i + 1]);
            return front_swaps + dfs(s, l + 1, r - 1);
        }

        for(int i = tail_pos + 1; i <= r; i ++) swap(s[i - 1], s[i]);
        return tail_swaps + dfs(s, l + 1, r - 1);
    }
};


int main() {

    cout << Solution().minMovesToMakePalindrome("aabb") << endl;
    // 2

    cout << Solution().minMovesToMakePalindrome("letelt") << endl;
    // 2

    cout << Solution().minMovesToMakePalindrome("eqvvhtcsaaqtqesvvqch") << endl;
    // 17

    return 0;
}
