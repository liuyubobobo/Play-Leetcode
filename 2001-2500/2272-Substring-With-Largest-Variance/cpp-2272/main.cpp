#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int largestVariance(string s) {

        int n = s.size();

        int res = 0;
        vector<vector<int>> min_d(26, vector<int>(26, INT_MAX / 2));
        vector<int> cur_f(26, 0);
        for(int r = 0; r < n; r ++){
            cur_f[s[r] - 'a'] ++;
            for(char c1 = 'a'; c1 <= 'z'; c1 ++)
                for(char c2 = 'a'; c2 <= 'z'; c2 ++){
                    if(c1 == c2) continue;
                    if(cur_f[c1] == 0 || cur)
                }
        }
        return res;
    }
};


int main() {

    string s = "aababbb";
    cout << Solution().largestVariance(s) << '\n';

    return 0;
}
