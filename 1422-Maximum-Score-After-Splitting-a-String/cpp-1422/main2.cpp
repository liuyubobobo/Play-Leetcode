/// Source : https://leetcode.com/problems/maximum-score-after-splitting-a-string/
/// Author : liuyubobobo
/// Time   : 2020-04-27

#include <iostream>
#include <vector>

using namespace std;


/// Presum and Postsum
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int maxScore(string s) {

        vector<int> presum(s.size() + 1, 0);
        for(int i = 0; i < s.size(); i ++)
            presum[i + 1] = presum[i] + (s[i] == '0');

        vector<int> postsum(s.size() + 1, 0);
        for(int i = s.size() - 1; i >= 0; i --)
            postsum[i] = postsum[i + 1] + (s[i] == '1');

        int res = 0;
        for(int i = 1; i < s.size(); i ++)
            res = max(res, presum[i] + postsum[i]);
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
