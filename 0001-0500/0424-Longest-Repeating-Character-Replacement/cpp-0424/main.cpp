/// Source : https://leetcode.com/problems/longest-repeating-character-replacement/
/// Author : liuyubobobo
/// Time   : 2021-02-01

#include <iostream>
#include <vector>

using namespace std;


/// Two Pointers
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {

public:
    int characterReplacement(string s, int k) {

        int res = 0;
        for(char c = 'A'; c <= 'Z'; c ++)
            res = max(res, solve(s, k, c));
        return res;
    }

private:
    int solve(const string& s, int k, char c){

        int n = s.size();
        vector<int> presum(n + 1, 0);
        for(int i = 0; i < n; i ++)
            presum[i + 1] = presum[i] + (s[i] == c);

        int l = 0, r = 0, res = 0;
        while(l <= n){
            if(r + 1 <= n && presum[r + 1] - presum[l] + k >= r + 1 - l)
                r ++, res = max(res, r - l);
            else
                l ++;
        }
        return res;
    }
};


int main() {

    cout << Solution().characterReplacement("ABAB", 2) << endl;
    // 4

    cout << Solution().characterReplacement("AABABBA", 1) << endl;
    // 4

    return 0;
}
