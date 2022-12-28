/// Source : https://leetcode.com/problems/minimize-the-maximum-of-two-arrays/description/
/// Author : liuyubobobo
/// Time   : 2022-12-28

#include <iostream>
#include <vector>

using namespace std;


/// Binary Search
/// Time Complexity: O(log(MAX_LONG_LONG))
/// Space Complexity: O(1)
class Solution {
public:
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {

        long long l = 1, r = 1000000000000000000ll;
        while(l < r){
            long long mid = (l + r) / 2;
            if(ok(mid, divisor1, divisor2, uniqueCnt1, uniqueCnt2)) r = mid;
            else l = mid + 1;
        }
        return l;
    }

private:
    bool ok(long long n, long long d1, long long d2, long long n1, long long n2){

        long long only1 = n / d1;
        long long only2 = n / d2;
        long long both12 = n / ((d1 * d2) / gcd(min(d1, d2), max(d1, d2)));

        long long left = n - only1 - only2 + both12;
        only1 -= both12, only2 -= both12;

        long long cnt1 = 0, cnt2 = 0;
        cnt1 += only2;
        if(cnt1 < n1) left -= (n1 - cnt1);

        if(left < 0) return false;

        cnt2 += only1 + left;
        return cnt2 >= n2;
    }

    long long gcd(long long a, long long b){
        if (a == 0) return b;
        return gcd(b % a, a);
    }
};


int main() {

    cout << Solution().minimizeSet(2, 4, 8, 2) << '\n';

    return 0;
}
