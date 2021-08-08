/// Source : https://leetcode.com/problems/maximum-product-of-the-length-of-two-palindromic-substrings/
/// Author : liuyubobobo
/// Time   : 2021-08-08

#include <iostream>
#include <vector>

using namespace std;


/// RK to find max length palindrome
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
template<typename T>
class StringHash{

private:
    int n;
    T B, MOD;
    vector<T> h, p;

public:
    StringHash(const string& s, T B = 128, T MOD = 1e9+ 7) :
    n(s.size()), h(n + 1, 0), p(n + 1, 1), B(B), MOD(MOD){

        for(int i = 0; i < n; i ++){
            h[i + 1] = (h[i] * B + s[i]) % MOD;
            p[i + 1] = p[i] * B % MOD;
        }
    }

    T get_hash(int l, int r){
        //        assert(l >= 0 && l < n);
        //        assert(r >= 0 && r < n);
        T res = (h[r + 1] - h[l] * p[r - l + 1]) % MOD;
        return res < 0 ? res + MOD : res;
    }
};


class Solution {
public:
    long long maxProduct(string s) {

        string rs = s;
        reverse(rs.begin(), rs.end());

        StringHash<long long> hash(s), rhash(rs);

        int n = s.size();
        vector<int> dp(n, 0);
        for(int i = 1; i + 1 < n; i ++){
            int lenl = 0, lenr = min(i, n - i - 1);
            while(lenl < lenr){
                int mid = (lenl + lenr + 1) / 2;
                if(hash.get_hash(i - mid, i - 1) == rhash.get_hash(n - 1 - (i + mid), n - 1 - (i + 1)))
                    lenl = mid;
                else
                    lenr = mid - 1;
            }

            dp[i] = lenl;
        }
//        for(int e: dp) cout << e << ' '; cout << endl;

        vector<int> left(n, 0);
        for(int i = 0; i < n; i ++)
            left[i - dp[i]] = max(left[i - dp[i]], 2 * dp[i] + 1);
        for(int i = 1; i < n; i ++)
            left[i] = max(left[i], left[i - 1] - 2);
//        for(int e: left) cout << e << ' '; cout << endl;

        for(int i = n - 2; i >= 0; i --)
            left[i] = max(left[i + 1], left[i]);
//        for(int e: left) cout << e << ' '; cout << endl;

        vector<int> right(n, 0);
        for(int i = 0; i < n; i ++)
            right[i + dp[i]] = max(right[i + dp[i]], 2 * dp[i] + 1);
        for(int i = n - 2; i >= 0; i --)
            right[i] = max(right[i], right[i + 1] - 2);
//        for(int e: right) cout << e << ' '; cout << endl;

        for(int i = 1; i < n; i ++)
            right[i] = max(right[i], right[i - 1]);
//        for(int e: right) cout << e << ' '; cout << endl;

        long long res = 0ll;
        for(int i = 1; i < n; i ++)
            res = max(res, (long long)right[i - 1] * left[i]);

        return res;
    }
};


int main() {

    cout << Solution().maxProduct("ababbb") << endl;
    // 9

    cout << Solution().maxProduct("zaaaxbbby") << endl;
    // 9

    cout << Solution().maxProduct("ggbswiymmlevedhkbdhntnhdbkhdevelmmyiwsbgg") << endl;
    // 45

    return 0;
}
