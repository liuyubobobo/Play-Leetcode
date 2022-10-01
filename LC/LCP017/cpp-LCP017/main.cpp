/// Source : https://leetcode-cn.com/problems/nGK0Fy/
/// Author : liuyubobobo
/// Time   : 2020-09-12

#include <iostream>

using namespace std;


/// Simulation
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int calculate(string s) {

        int x = 1, y = 0;
        for(char c: s)
            if(c == 'A') x = 2 * x + y;
            else y = 2 * y + x;
        return x + y;
    }
};


int main() {

    cout << Solution().calculate("AB") << endl;
    // 4

    return 0;
}
