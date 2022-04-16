/// Source : https://leetcode.com/problems/number-of-ways-to-buy-pens-and-pencils/
/// Author : liuyubobobo
/// Time   : 2022-04-16

#include <iostream>

using namespace std;


/// Math
/// Time Complexity: O(total / cost1)
/// Space Complexity: O(1)
class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {

        long long res = 0;
        for(int cnt1 = 0; cost1 * cnt1 <= total; cnt1 ++){
            res += (total - cost1 * cnt1) / cost2 + 1;
        }
        return res;
    }
};


int main() {

    return 0;
}
