/// Source : https://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating/
/// Author : liuyubobobo
/// Time   : 2021-06-05

#include <iostream>
#include <vector>

using namespace std;


/// Presum
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int minFlips(string s) {

        int n = s.size();

        vector<int> zerof(n);
        zerof[0] = (s[0] != '0');
        int t = 0;
        for(int i = 1; i < n; i ++){
            t = 1 - t;
            zerof[i] = zerof[i - 1] + (s[i] != '0' + t);
        }
//        for(int e: zerof) cout << e << " "; cout << endl;

        vector<int> onef(n);
        onef[0] = (s[0] != '1');
        t = 1;
        for(int i = 1; i < n; i ++){
            t = 1 - t;
            onef[i] = onef[i - 1] + (s[i] != '0' + t);
        }
//        for(int e: onef) cout << e << " "; cout << endl;

        vector<int> zerob(n);
        zerob[n - 1] = (s[n - 1] != '0');
        t = 0;
        for(int i = n - 2; i >= 0; i --){
            t = 1 - t;
            zerob[i] = zerob[i + 1] + (s[i] != '0' + t);
        }
//        for(int e: zerob) cout << e << " "; cout << endl;

        vector<int> oneb(n);
        oneb[n - 1] = (s[n - 1] != '1');
        t = 1;
        for(int i = n - 2; i >= 0; i --){
            t = 1 - t;
            oneb[i] = oneb[i + 1] + (s[i] != '0' + t);
        }
//        for(int e: oneb) cout << e << " "; cout << endl;

        int res = min(zerof[n - 1], onef[n - 1]);
        for(int i = 1; i < n; i ++){
            res = min(res, zerob[i] + onef[i - 1]);
            res = min(res, oneb[i] + zerof[i - 1]);
        }
        return res;
    }
};


int main() {

    cout << Solution().minFlips("111000") << endl;
    // 2

    cout << Solution().minFlips("010") << endl;
    // 0

    cout << Solution().minFlips("1110") << endl;
    // 1

    cout << Solution().minFlips("01001001101") << endl;
    // 2

    return 0;
}
