/// Source : https://leetcode.com/problems/substring-with-largest-variance/description/
/// Author : liuyubobobo
/// Time   : 2023-07-09

#include <iostream>
#include <vector>

using namespace std;


/// DP
/// Time Complexity: O(n * 26 * 26)
/// Space Complexity: O(n)
class Solution {
public:
    int largestVariance(string s) {

        int n = s.size();

        int res = 0;
        for(char max_c = 'a'; max_c <= 'z'; max_c ++)
            for(char min_c = 'a'; min_c <= 'z'; min_c ++){
                if(max_c == min_c) continue;
                res = max(res, solve(n, s, max_c, min_c));
                res = max(res, solve(n, s, max_c, min_c, true));
            }
        return res;
    }

private:
    int solve(int n, const string& s, char max_c, char min_c, bool reverse = false){

        vector<int> v(n);
        if(!reverse){
            for(int i = 0; i < n; i ++)
                v[i] = ((s[i] == max_c ? 1 : (s[i] == min_c ? -1 : 0)));
        }
        else{
            for(int i = n - 1; i >= 0; i --)
                v[n - 1 - i] = (s[i] == max_c ? 1 : (s[i] == min_c ? -1 : 0));
        }

        int res = 0, cur = 0;
        bool hit_neg = false;
        for(int e: v){
            if(cur + e >= 0){
                cur += e;
                if(e < 0) hit_neg = true;
                if(hit_neg) res = max(res, cur);
            }
            else cur = 0, hit_neg = false;
        }
        return res;
    }
};


int main() {

    string s1 = "aababbb";
    cout << Solution().largestVariance(s1) << '\n';
    // 3

    string s2 = "abcde";
    cout << Solution().largestVariance(s2) << '\n';
    // 0

    string s3 = "lripaa";
    cout << Solution().largestVariance(s3) << '\n';
    // 1

    return 0;
}
