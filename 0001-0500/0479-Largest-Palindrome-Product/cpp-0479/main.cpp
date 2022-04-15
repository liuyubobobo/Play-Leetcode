/// Source : https://leetcode.com/problems/largest-palindrome-product/
/// Author : liuyubobobo
/// Time   : 2022-04-15

#include <iostream>
#include <vector>

using namespace std;


/// Iterate Palindrome
/// Time Complexity: O(10^(2n)) in theory but in fact it is very fast
/// Space Complexity: O(n)
class Solution {
public:
    int largestPalindrome(int n) {

        long long maxv = pow(10, n) - 1;
        long long minv = pow(10, n - 1);
        for(int a = maxv; a >= minv; a --){
            long long num = get_palindrome_num(a);

            for(long long d = maxv; d >= minv; d --){
                long long nd = num / d;
                if(nd > d) break;
                if(d * nd == num) return num % 1337ll;
            }
        }
        return 9;
    }

private:
    long long get_palindrome_num(int a){
        string left = to_string(a);
        string right = left;
        reverse(right.begin(), right.end());
        string res = left + right;
        return atoll(res.c_str());
    }
};


int main() {

    cout << Solution().largestPalindrome(2) << '\n';
    // 987

    return 0;
}
