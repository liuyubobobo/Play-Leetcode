/// Source : https://leetcode.com/problems/check-if-an-original-string-exists-given-two-encoded-strings/
/// Author : liuyubobobo
/// Time   : 2021-11-01

#include <iostream>
#include <vector>
#include <map>

using namespace std;


/// Memoization
/// Time Compelxity: O(n1 * n2 * 10000)
/// Space Compelxity: O(n1 * n2 * 10000)
class Solution {
public:
    bool possiblyEquals(string s1, string s2) {

        map<pair<pair<int, int>, int>, bool> dp; // (i1, i2), diff = line1 - line2
        return dfs(s1, s2, 0, 0, 0, dp);
    }

private:
    bool dfs(const string& s1, const string& s2, int i1, int i2, int diff,
             map<pair<pair<int, int>, int>, bool>& dp){

        if(i1 == s1.size() && i2 == s2.size()) return diff == 0;

        pair<pair<int, int>, int> cur_state = {{i1, i2}, diff};
        if(dp.count(cur_state)) return dp[cur_state];

        if(i1 == s1.size()){
            if(diff <= 0) return false;

            if(!isdigit(s2[i2]))
                return dp[cur_state] = dfs(s1, s2, i1, i2 + 1, diff - 1, dp);

            for(int len = 0; len < 3 && i2 + len < s2.size() && isdigit(s2[i2 + len]); len ++)
                if(dfs(s1, s2, i1, i2 + len + 1, diff - atoi(s2.substr(i2, len + 1).c_str()), dp))
                    return dp[cur_state] = true;
            return dp[cur_state] = false;
        }

        if(i2 == s2.size()){
            if(diff >= 0) return false;

            if(!isdigit(s1[i1]))
                return dp[cur_state] = dfs(s1, s2, i1 + 1, i2, diff + 1, dp);

            for(int len = 0; len < 3 && i1 + len < s1.size() && isdigit(s1[i1 + len]); len ++)
                if(dfs(s1, s2, i1 + len + 1, i2, diff + atoi(s1.substr(i1, len + 1).c_str()), dp))
                    return dp[cur_state] = true;
            return dp[cur_state] = false;
        }

        if(!isdigit(s1[i1]) && !isdigit(s2[i2])){
            if(diff){
                if(diff > 0) return dp[cur_state] = dfs(s1, s2, i1, i2 + 1, diff - 1, dp);
                return dp[cur_state] = dfs(s1, s2, i1 + 1, i2, diff + 1, dp);
            }

            if(s1[i1] == s2[i2])
                return dp[cur_state] = dfs(s1, s2, i1 + 1, i2 + 1, diff, dp);
            return dp[cur_state] = false;
        }

        if(!isdigit(s1[i1]) && isdigit(s2[i2])){
            if(diff < 0)
                return dp[cur_state] = dfs(s1, s2, i1 + 1, i2, diff + 1, dp);

            for(int len = 0; len < 3 && i2 + len < s2.size() && isdigit(s2[i2 + len]); len ++)
                if(dfs(s1, s2, i1, i2 + len + 1, diff - atoi(s2.substr(i2, len + 1).c_str()), dp))
                    return dp[cur_state] = true;
            return dp[cur_state] = false;
        }

        if(isdigit(s1[i1]) && !isdigit(s2[i2])){
            if(diff > 0)
                return dp[cur_state] = dfs(s1, s2, i1, i2 + 1, diff - 1, dp);

            for(int len = 0; len < 3 && i1 + len < s1.size() && isdigit(s1[i1 + len]); len ++)
                if(dfs(s1, s2, i1 + len + 1, i2, diff + atoi(s1.substr(i1, len + 1).c_str()), dp))
                    return dp[cur_state] = true;
            return dp[cur_state] = false;
        }

        assert(isdigit(s1[i1]) && isdigit(s2[i2]));
        for(int len1 = 0; len1 < 3 && i1 + len1 < s1.size() && isdigit(s1[i1 + len1]); len1 ++)
            if(dfs(s1, s2, i1 + len1 + 1, i2, diff + atoi(s1.substr(i1, len1 + 1).c_str()), dp))
                return dp[cur_state] = true;
        return dp[cur_state] = false;
    }
};


int main() {

    cout << Solution().possiblyEquals("internationalization", "i18n") << endl;
    // true

    cout << Solution().possiblyEquals("l123e", "44") << endl;
    // true

    cout << Solution().possiblyEquals("a5b", "c5b") << endl;
    // false

    cout << Solution().possiblyEquals("112s", "g841") << endl;
    // true

    cout << Solution().possiblyEquals("ab", "a2") << endl;
    // false

    cout << Solution().possiblyEquals("1", "z") << endl;
    // true

    cout << Solution().possiblyEquals("a312b4a77", "a428a1a8a") << endl;
    // true

    cout << Solution().possiblyEquals("98u8v8v8v89u888u998v88u98v88u9v99u989v8u", "9v898u98v888v89v998u98v9v888u9v899v998u9") << endl;
    // false

    return 0;
}
