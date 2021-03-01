/// Source : https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/
/// Author : liuyubobobo
/// Time   : 2021-03-01

#include <iostream>
#include <vector>

using namespace std;


/// Divide and Conquered
/// Time Complexity: O(nlogn)
/// Space Complexity: O(logn)
class Solution {
public:
    int longestSubstring(string s, int k) {

        int n = s.size();
        vector<vector<int>> presum(26, vector<int>(n + 1, 0));
        for(int i = 0; i < n; i ++)
            for(int c = 0; c < 26; c ++)
                presum[c][i + 1] = presum[c][i] + (s[i] == 'a' + c);

        return solve(s, k, 0, n - 1, presum);
    }

private:
    int solve(const string& s, int k, int l, int r, const vector<vector<int>>& presum){

        if(l > r || r - l + 1 < k) return 0;

        int breakchar = -1;
        for(int c = 0; c < 26; c ++)
            if((presum[c][r + 1] - presum[c][l]) && presum[c][r + 1] - presum[c][l] < k){
                breakchar = c;
                break;
            }

        if(breakchar == -1) return r - l + 1;

        int pos = -1;
        for(int i = l; i <= r; i ++)
            if(s[i] == 'a' + breakchar){
                pos = i;
                break;
            }
        return max(solve(s, k, l, pos - 1, presum), solve(s, k, pos + 1, r, presum));
    }
};


int main() {

    cout << Solution().longestSubstring("aaabb", 3) << endl;
    // 3

    return 0;
}
