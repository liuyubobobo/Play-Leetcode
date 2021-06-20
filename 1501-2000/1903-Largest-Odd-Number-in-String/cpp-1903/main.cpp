/// Source : https://leetcode.com/problems/largest-odd-number-in-string/
/// Author : liuyubobobo
/// Time   : 2021-06-20

#include <iostream>
#include <vector>

using namespace std;


/// Greedy
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    string largestOddNumber(string num) {

        int i;
        for(i = num.size() - 1; i >= 0; i --)
            if((num[i] - '0') % 2)
                break;

        return num.substr(0, i + 1);
    }
};


int main() {

    cout << Solution().largestOddNumber("52") << endl;
    // 5

    cout << Solution().largestOddNumber("4206") << endl;
    // ""

    cout << Solution().largestOddNumber("35427") << endl;
    // 35427

    return 0;
}
