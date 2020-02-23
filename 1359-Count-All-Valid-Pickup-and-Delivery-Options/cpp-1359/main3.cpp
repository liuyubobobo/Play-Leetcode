/// Source : https://leetcode.com/problems/count-all-valid-pickup-and-delivery-options/
/// Author : liuyubobobo
/// Time   : 2020-02-23

#include <iostream>
#include <vector>

using namespace std;


/// Mathematics
/// Time Complexity: O(n)
/// Space Complxity: O(1)
class Solution {

private:
    long long MOD = 1e9 + 7;

public:
    int countOrders(int n) {

        int res = 1;
        for(int i = 0; i + 1 < n; i ++)
            res = (long long)res * (long long)(n - i) * (long long)(2 * (n - i) - 1) % MOD;
        return res;
    }
};


int main() {

    cout << Solution().countOrders(1) << endl;
    // 1

    cout << Solution().countOrders(2) << endl;
    // 6

    return 0;
}
