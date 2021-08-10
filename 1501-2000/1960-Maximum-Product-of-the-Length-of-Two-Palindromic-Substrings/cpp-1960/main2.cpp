/// Source : https://leetcode.com/problems/maximum-product-of-the-length-of-two-palindromic-substrings/
/// Author : liuyubobobo
/// Time   : 2021-08-08

#include <iostream>
#include <vector>

using namespace std;


/// Manacher
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    long long maxProduct(string s) {

        int n = s.size();

        vector<int> d1(n);
        for (int i = 0, l = 0, r = -1; i < n; i++) {
            int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
            while (0 <= i - k && i + k < n && s[i - k] == s[i + k])
                k++;

            d1[i] = --k;
            if (i + k > r) l = i - k, r = i + k;
        }

        vector<int> left(n, 0);
        for(int i = 0; i < n; i ++)
            left[i - d1[i]] = max(left[i - d1[i]], 2 * d1[i] + 1);
        for(int i = 1; i < n; i ++)
            left[i] = max(left[i], left[i - 1] - 2);
        //        for(int e: left) cout << e << ' '; cout << endl;

        for(int i = n - 2; i >= 0; i --)
            left[i] = max(left[i + 1], left[i]);
        //        for(int e: left) cout << e << ' '; cout << endl;

        vector<int> right(n, 0);
        for(int i = 0; i < n; i ++)
            right[i + d1[i]] = max(right[i + d1[i]], 2 * d1[i] + 1);
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
