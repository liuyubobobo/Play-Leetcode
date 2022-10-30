/// Source : https://leetcode.com/problems/minimum-addition-to-make-integer-beautiful/
/// Author : liuyubobobo
/// Time   : 2022-10-29

#include <iostream>
#include <vector>

using namespace std;


/// Greedy
/// Time Complexity: O((logn)^2)
/// Space Complexity: O(logn)
class Solution {
public:
    long long makeIntegerBeautiful(long long n, int target) {

        vector<long long> pow10(18, 1ll);
        for(int i = 1; i < 18; i ++)
            pow10[i] = pow10[i - 1] * 10ll;

        long long res = 0;
        while(true){
            string s = to_string(n);
            int len = s.size();

            if(digit_sum(len, s) <= target) break;

            int first_non_zero = len - 1;
            for(first_non_zero = len - 1; first_non_zero >= 0; first_non_zero --)
                if(s[first_non_zero] != '0') break;

            long long d = (10 - (s[first_non_zero] - '0')) * pow10[len - first_non_zero - 1];
            res += d;
            n += d;
        }
        return res;
    }

private:
    int digit_sum(int n, const string& s){
        int res = 0;
        for(char d: s)
            res += (d - '0');
        return res;
    }
};


int main() {

    cout << Solution().makeIntegerBeautiful(16, 6) << '\n';
    // 4

    cout << Solution().makeIntegerBeautiful(467, 6) << '\n';
    // 33

    cout << Solution().makeIntegerBeautiful(1, 1) << '\n';
    // 0

    return 0;
}
