/// Source : https://leetcode-cn.com/problems/Ju9Xwi/
/// Author : liuyubobobo
/// Time   : 2021-06-19

#include <iostream>
#include <vector>

using namespace std;


/// Greedy
/// Time Complexity: O(logn)
/// Space Complexity: O(1)
class Solution {
public:
    int leastMinutes(int n) {

        int res = 1, cur = 1;
        while(cur < n)
            res ++, cur *= 2;
        return res;
    }
};


int main() {

    cout << Solution().leastMinutes(2) << endl;
    // 2

    cout << Solution().leastMinutes(4) << endl;
    // 3

    cout << Solution().leastMinutes(7) << endl;
    // 4

    return 0;
}
