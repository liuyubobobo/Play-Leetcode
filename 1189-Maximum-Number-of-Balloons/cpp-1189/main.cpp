/// Source : https://leetcode.com/problems/maximum-number-of-balloons/
/// Author : liuyubobobo
/// Time   : 2019-09-14

#include <iostream>
#include <vector>

using namespace std;


/// HashMap Counting
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int maxNumberOfBalloons(string text) {

        vector<int> freq(26, 0);
        for(char c: text) freq[c - 'a'] ++;

        int res = freq['b' - 'a'];
        res = min(res, freq['a' - 'a']);
        res = min(res, freq['l' - 'a'] / 2);
        res = min(res, freq['o' - 'a'] / 2);
        res = min(res, freq['n' - 'a']);
        return res;
    }
};


int main() {

    cout << Solution().maxNumberOfBalloons("loonbalxballpoon") << endl;
    // 2

    return 0;
}