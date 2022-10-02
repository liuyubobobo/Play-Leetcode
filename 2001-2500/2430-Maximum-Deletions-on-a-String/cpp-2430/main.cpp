/// Source : https://leetcode.com/problems/maximum-deletions-on-a-string/
/// Author : liuyubobobo
/// Time   : 2022-10-01

#include <iostream>
#include <vector>

using namespace std;


/// RK + DP
/// Time Complexity: O(n^2)
/// Space Complexity: O(n)
class StringHashU{

private:
    int n;
    unsigned long long B;
    vector<unsigned long long> h, p;

public:
    StringHashU(const string& s, unsigned long long B = 13331) :
            n(s.size()), h(n + 1, 0), p(n + 1, 1), B(B){

        for(int i = 0; i < n; i ++){
            h[i + 1] = h[i] * B + s[i];
            p[i + 1] = p[i] * B;
        }
    }

    unsigned long long get_hash(int l, int r){
        assert(l >= 0 && l < n);
        assert(r >= 0 && r < n);
        return h[r + 1] - h[l] * p[r - l + 1];
    }
};

class Solution {
public:
    int deleteString(string s) {

        StringHashU hash(s);

        int n = s.size();
        vector<int> dp(n + 1, 0);
        dp[n - 1] = 1;
        for(int start = n - 2; start >= 0; start --){
            int len = n - start, tres = 1;
            for(int i = 1; i <= len / 2; i ++)
                if(hash.get_hash(start, start + i - 1) == hash.get_hash(start + i, start + 2 * i - 1))
                    tres = max(tres, 1 + dp[start + i]);
            dp[start] = tres;
        }
        return dp[0];
    }
};


int main() {

    string s2 = "aaabaab";
    cout << Solution().deleteString(s2) << '\n';
    // 4

    return 0;
}
