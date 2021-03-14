/// Source : https://leetcode.com/problems/sum-of-beauty-of-all-substrings/
/// Author : liuyubobobo
/// Time   : 2021-03-11

#include <iostream>
#include <vector>

using namespace std;


/// Presum
/// Time Complexity: O(n^2)
/// Space Complexity: O(n)
class Solution {
public:
    int beautySum(string s) {

        int n = s.size();

        vector<vector<int>> presum(26, vector<int>(n + 1, 0));
        for(int c = 0; c < 26; c ++)
            for(int i = 0; i < n; i ++)
                presum[c][i + 1] = presum[c][i] + (s[i] == ('a' + c));

        int res = 0;
        for(int start = 0; start < n; start ++)
            for(int end = start; end < n; end ++){
                int maxf = INT_MIN, minf = INT_MAX;
                for(int c = 0; c < 26; c ++){
                    int f = presum[c][end + 1] - presum[c][start];
                    if(f)
                        maxf = max(maxf, f),
                        minf = min(minf, f);
                }

                res += (maxf - minf);
            }
        return res;
    }
};


int main() {

    cout << Solution().beautySum("aabcb") << endl;
    // 5

    cout << Solution().beautySum("aabcbaa") << endl;
    // 17

    return 0;
}
