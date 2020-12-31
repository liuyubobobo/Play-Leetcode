/// Source : https://leetcode.com/problems/maximum-score-after-splitting-a-string/
/// Author : liuyubobobo
/// Time   : 2020-04-25

#include <iostream>

using namespace std;


/// Brute Force
/// Time Complexity: O(n^2)
/// Space Complexity: O(1)
class Solution {
public:
    int maxScore(string s) {

        int res = 0;
        for(int i = 1; i < s.size(); i ++){

            int tres = 0;
            for(int j = 0; j < i; j ++) tres += (s[j] == '0');
            for(int j = i; j < s.size(); j ++) tres += (s[j] == '1');
            res = max(res, tres);
        }
        return res;
    }
};


int main() {

    cout << Solution().maxScore("011101") << endl;
    // 5

    cout << Solution().maxScore("00111") << endl;
    // 5

    cout << Solution().maxScore("1111") << endl;
    // 3

    cout << Solution().maxScore("00") << endl;
    // 1

    return 0;
}
