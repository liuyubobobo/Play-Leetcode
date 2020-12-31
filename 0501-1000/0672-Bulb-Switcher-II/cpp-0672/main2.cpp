/// Source : https://leetcode.com/problems/bulb-switcher-ii/description/
/// Author : liuyubobobo
/// Time   : 2017-12-02

#include <iostream>
#include <unordered_set>

using namespace std;

/// For further analysis, we can see the first three lights uniquely determine the rest of the sequence
/// Assume the four operation is a, b, c, d, then:
/// - Light 1 = 1 + a + c + d
/// - Light 2 = 1 + a + b
/// - Light 3 = 1 + a + c
/// - Light 4 = 1 + a + b + d
/// - Light 5 = 1 + a + c
/// - Light 6 = 1 + a + b
///
/// so that (module 2)
/// - Light 4 = (Light 1) + (Light 2) + (Light 3)
/// - Light 5 = Light 3
/// - Light 6 = Light 2
///
/// so there's just 8 cases, we can enumerate all these 8 cases and get the result.
///
/// Time Complexity: O(1)
/// Space Complexity: O(1)
class Solution {
public:
    int flipLights(int n, int m) {

        n = min(n, 3);
        if (m == 0) return 1;
        if (m == 1) return n == 1 ? 2 : n == 2 ? 3 : 4;
        if (m == 2) return n == 1 ? 2 : n == 2 ? 4 : 7;
        return n == 1 ? 2 : n == 2 ? 4 : 8;
    }
};

int main() {

    cout << Solution().flipLights(1, 1) << endl;
    cout << Solution().flipLights(2, 1) << endl;
    cout << Solution().flipLights(3, 1) << endl;
    cout << Solution().flipLights(3, 3) << endl;
    cout << Solution().flipLights(3, 2) << endl;

    return 0;
}