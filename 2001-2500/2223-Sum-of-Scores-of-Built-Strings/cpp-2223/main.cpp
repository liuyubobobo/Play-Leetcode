/// Source : https://leetcode.com/problems/sum-of-scores-of-built-strings/
/// Author : liuyubobobo
/// Time   : 2022-04-02

#include <iostream>
#include <vector>

using namespace std;


/// z-algo
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    long long sumScores(string s) {

        vector<int> v = z_function(s);
//        for(int e: v) cout << e << ' '; cout << '\n';

        long long res = 0;
        for(int e: v) res += e;
        return res + (long long)s.size();
    }

private:
    vector<int> z_function(string s) {

        int n = (int)s.length();
        vector<int> z(n);

        for (int i = 1, l = 0, r = 0; i < n; ++i) {
            if (i <= r && z[i - l] < r - i + 1)
                z[i] = z[i - l];
            else{
                z[i] = max(0, r - i + 1);
                while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
            }

            if (i + z[i] - 1 > r)
                l = i, r = i + z[i] - 1;
        }
        return z;
    }
};


int main() {

    cout << Solution().sumScores("babab") << '\n';

    return 0;
}
