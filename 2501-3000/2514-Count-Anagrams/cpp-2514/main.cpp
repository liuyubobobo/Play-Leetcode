/// Source : https://leetcode.com/problems/count-anagrams/
/// Author : liuyubobobo
/// Time   : 2022-12-28

#include <iostream>
#include <vector>

using namespace std;


/// Math
/// Time Complexity: O(n)
/// Space Compelxity: O(n)
class Solution {

private:
    long long MOD = 1e9 + 7;

public:
    int countAnagrams(string s) {

        int n = s.size();
        vector<long long> fac(n + 1, 1);
        for(int i = 2; i <= n; i ++) fac[i] = fac[i - 1] * i % MOD;

        vector<long long> ifac(n + 1);
        for(int i = 0; i <= n; i ++) ifac[i] = quick_pow(fac[i], MOD - 2);

        long long res = 1;
        for(int start = 0, i = 1; i <= n; i ++){
            if(i == n || s[i] == ' '){
                string word = s.substr(start, i - start);
                res *= get_cnt(word, fac, ifac);
                res %= MOD;

                start = i + 1;
                i = start;
            }
        }
        return res;
    }

private:
    long long get_cnt(const string& word,
                      const vector<long long>& fac, const vector<long long>& ifac){

        vector<int> f(26, 0);
        for(char c: word) f[c - 'a'] ++;

        int n = word.size();
        long long res = fac[n];
        for(int i = 0; i < 26; i ++)
            res = res * ifac[f[i]] % MOD;
        return res;
    }

    long long quick_pow(long long a, long long k) {
        long long res = 1ll;
        while (k) {
            if (k & 1) res = res * a % MOD;
            a = a * a % MOD;
            k >>= 1;
        }
        return res % MOD;
    }
};


int main() {

    string s1 = "aa";
    cout << Solution().countAnagrams(s1) << '\n';

    return 0;
}
