/// Source : https://leetcode.com/problems/minimum-number-of-operations-to-make-string-sorted/
/// Author : liuyubobobo
/// Time   : 2021-05-05

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


/// Combination
/// Time Complexity: O(|s|*log(MOD))
/// Space Complexity: O(|s|)
class Solution {

private:
    long long MOD = 1e9 + 7;

public:
    int makeStringSorted(string s) {

        vector<long long> perm(s.size() + 1, 1);
        for(int i = 1; i <= s.size(); i ++)
            perm[i] = perm[i - 1] * (long long)i % MOD;

        vector<long long> perminv(s.size() + 1, 1);
        for(int i = 1; i <= s.size(); i ++)
            perminv[i] = mypow(perm[i], MOD - 2);

        vector<int> f(26, 0);
        for(char c: s) f[c - 'a'] ++;
        return dfs(s, 0, f, perm, perminv);
    }

private:
    long long dfs(const string& s, int index, vector<int>& f,
                  const vector<long long>& perm, const vector<long long>& perminv){

        if(index == s.size()) return 0;

        long long res = 0ll;
        for(int i = 0; i < s[index] - 'a'; i ++)
            if(f[i]){
                f[i] --;
                res += permutation_num(f, perm, perminv);
                res %= MOD;
                f[i] ++;
            }

        f[s[index] - 'a'] --;
        res += dfs(s, index + 1, f, perm, perminv);
        res %= MOD;
        return res;
    }

private:
    long long permutation_num(const vector<int>& f, const vector<long long>& perm,
                              const vector<long long>& perminv){

        int sum = accumulate(f.begin(), f.end(), 0);
        long long res = perm[sum];
        for(int e: f){
//                assert(f[e] < perm.size());
            res = (long long)res * perminv[e] % MOD;
        }
        return res;
    }

    long long mypow(long long n, int k){

        if(k == 0) return 1ll;
        if(k == 1) return n;

        long long half = mypow(n, k / 2);
        long long res = half * half % MOD;
        if(k % 2) res = res * n % MOD;
        return res;
    }
};


int main() {

    cout << Solution().makeStringSorted("cba") << endl;
    // 5

    cout << Solution().makeStringSorted("aabaa") << endl;
    // 2

    cout << Solution().makeStringSorted("cdbea") << endl;
    // 63

    cout << Solution().makeStringSorted("leetcodeleetcodeleetcode") << endl;
    // 982157772

    return 0;
}
