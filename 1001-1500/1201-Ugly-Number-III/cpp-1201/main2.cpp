/// Source : https://leetcode.com/problems/ugly-number-iii/
/// Author : liuyubobobo
/// Time   : 2019-09-22

#include <iostream>

using namespace std;


/// Binary Search (Lower Bound)
/// Time Complexity: O(max*log(max)) where max = 2e9
/// Space Complexity: O(1)
class Solution {
public:
    int nthUglyNumber(int n, int a, int b, int c) {

        long long l = 1ll, r = 2000000000ll;
        while(l < r){
            long long mid = (l + r) / 2;
            int pos = get_pos(mid, a, b, c);
            if(pos < n) l = mid + 1;
            else r = mid;
        }
        return l;
    }

private:
    int get_pos(long long num, long long a, long long b, long long c){

        long long res = 0;
        res = num / a + num / b + num / c;
        res -= (num / lcm(a, b) + num / lcm(b, c) + num / lcm(a, c));
        res += num / lcm(lcm(a, b), c);
        return res;
    }

    long long lcm(long long a, long long b){
        return a / gcd(a, b) * b;
    }

    long long gcd(long long a, long long b){

        if(a < b) swap(a, b);
        if(a % b == 0) return b;
        return gcd(b, a % b);
    }
};


int main() {

    cout << Solution().nthUglyNumber(3, 2, 3, 5) << endl;
    // 4

    cout << Solution().nthUglyNumber(4, 2, 3, 4) << endl;
    // 6

    cout << Solution().nthUglyNumber(5, 2, 11, 13) << endl;
    // 10

    cout << Solution().nthUglyNumber(1000000000, 2, 217983653, 336916467) << endl;
    // 1999999984

    return 0;
}