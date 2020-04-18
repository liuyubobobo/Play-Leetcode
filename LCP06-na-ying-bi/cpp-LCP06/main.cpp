/// Source : https://leetcode-cn.com/problems/na-ying-bi/solution/
/// Author : liuyubobobo
/// Time   : 2020-04-17

#include <iostream>
#include <vector>

using namespace  std;


/// Linear Scan
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int minCount(vector<int>& coins) {

        int res = 0;
        for(int e: coins)
            res += e / 2 + e % 2;
        return res;
    }
};


int main() {

    vector<int> coins1 = {4, 2, 1};
    cout << Solution().minCount(coins1) << endl;
    // 4

    vector<int> coins2 = {2, 3, 10};
    cout << Solution().minCount(coins2) << endl;
    // 8

    return 0;
}