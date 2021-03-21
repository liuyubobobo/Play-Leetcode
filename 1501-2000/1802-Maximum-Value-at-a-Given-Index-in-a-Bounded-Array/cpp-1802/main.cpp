/// Source : https://leetcode.com/problems/maximum-value-at-a-given-index-in-a-bounded-array/
/// Author : liuyubobobo
/// Time   : 2021-03-20

#include <iostream>

using namespace std;


/// Binary Search
/// Time Complexity: O(log(maxSum))
/// Space Complexity: O(1)
class Solution {
public:
    int maxValue(int n, int index, int maxSum) {

        long long l = 1ll, r = (long long)maxSum;
        while(l < r){

            long long mid = (l + r + 1ll) / 2ll;
            if(ok(n, index, maxSum, mid)) l = mid;
            else r = mid - 1ll;
        }
        return l;
    }

private:
    bool ok(int n, int index, long long maxSum, long long k){

        int left = index, right = n - index - 1;
        long long sum = 0ll;
        if(left) sum += get_sum(k - 1, left);
        if(right) sum += get_sum(k - 1, right);
        return sum + k <= maxSum;
    }

    long long get_sum(long long maxv, int n){

        if(maxv - (long long)(n - 1) > 0)
            return (maxv + maxv - (long long)(n - 1)) * (long long)n / 2ll;

        int n1 = maxv;
        long long sum = (maxv + maxv - (long long)(n1 - 1)) * (long long)n1 / 2ll;
        return sum + (long long)(n - n1);
    }
};


int main() {

    cout << Solution().maxValue(4, 2, 6) << endl;
    // 2

    cout << Solution().maxValue(6, 1, 10) << endl;
    // 3

    cout << Solution().maxValue(3, 2, 18) << endl;
    // 7

    cout << Solution().maxValue(8, 7, 14) << endl;
    // 4

    return 0;
}
