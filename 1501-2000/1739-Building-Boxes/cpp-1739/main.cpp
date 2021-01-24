/// Source : https://leetcode.com/problems/building-boxes/
/// Author : liuyubobobo
/// Time   : 2021-01-23

#include <iostream>

using namespace std;


/// Mathematics
/// Time Complexity: O(sqrt(n))
/// Space Complexity: O(1)
class Solution {
public:
    int minimumBoxes(int n) {

        int total = 0, res = 0;
        for(int h = 1; h <= n && total < n; h ++){
            for(int x = 1; x <= h && total < n; x ++)
                total += x, res ++;
        }
        return res;
    }
};


int main() {

    cout << Solution().minimumBoxes(3) << endl;
    // 3

    cout << Solution().minimumBoxes(4) << endl;
    // 3

    cout << Solution().minimumBoxes(10) << endl;
    // 6

    cout << Solution().minimumBoxes(11) << endl;
    // 7

    cout << Solution().minimumBoxes(1e9) << endl;
    // 1650467

    return 0;
}
