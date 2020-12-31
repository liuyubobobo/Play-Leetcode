/// Source : https://leetcode.com/problems/divisor-game/
/// Author : liuyubobobo
/// Time   : 2019-04-13

#include <iostream>
#include <vector>

using namespace std;


/// Mathematics
/// Prove can be see here: https://leetcode.com/problems/divisor-game/discuss/274606/JavaC%2B%2BPython-return-N-2-0
///
/// Time Complexity: O(1)
/// Space Complexity: O(1)
class Solution {

public:
    bool divisorGame(int N) {
        return N % 2 == 0;
    }
};


int main() {

    cout << Solution().divisorGame(2) << endl; // true
    cout << Solution().divisorGame(3) << endl; // false
    cout << Solution().divisorGame(9) << endl; // false

    return 0;
}