/// Source : https://leetcode.com/problems/minimum-time-to-remove-all-cars-containing-illegal-goods/
/// Author : liuyubobobo
/// Time   : 2022-02-06

#include <iostream>
#include <vector>

using namespace std;


/// Linear Scan
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int minimumTime(string s) {

        int n = s.size();

        int res = n, minv = 0;
        for(int r = 0; r < n; r ++){
            minv = min(r, minv) + 2 * (s[r] == '1');
            res = min(res, n - 1 - r + minv);
        }
        return res;
    }
};


int main() {

    string s1 = "1100101";
    cout << Solution().minimumTime(s1) << endl;
    // 5

    string s2 = "0010";
    cout << Solution().minimumTime(s2) << endl;
    // 2

    string s3 = "011001111111101001010000001010011";
    cout << Solution().minimumTime(s3) << endl;
    // 25

    return 0;
}
