/// Source : https://leetcode.com/problems/find-the-winner-of-the-circular-game/
/// Author : liuyubobobo
/// Time   : 2021-04-10

#include <iostream>

using namespace std;


/// Mathematics
/// Joseph Problem
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int findTheWinner(int n, int k) {

        int s = 0;
        for (int i = 2; i <= n; i++)
            s = (s + k) % i;
        return s + 1;
    }
};


int main() {

    cout << Solution().findTheWinner(5, 2) << endl;
    // 3

    cout << Solution().findTheWinner(6, 5) << endl;
    // 1

    return 0;
}
