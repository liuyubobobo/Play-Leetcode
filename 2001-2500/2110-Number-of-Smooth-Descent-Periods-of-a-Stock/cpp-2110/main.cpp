/// Source : https://leetcode.com/problems/number-of-smooth-descent-periods-of-a-stock/
/// Author : liuyubobobo
/// Time   : 2021-12-18

#include <iostream>
#include <vector>

using namespace std;


/// Split
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {

        int n = prices.size();

        long long res = 0;
        for(int start = 0, i = 1; i <= n; i ++)
            if(i == n || prices[i] + 1 != prices[i - 1]){
                long long len = i - start;
                res += (len + 1ll) * len / 2ll;

                start = i;
            }
        return res;
    }
};


int main() {

    return 0;
}
