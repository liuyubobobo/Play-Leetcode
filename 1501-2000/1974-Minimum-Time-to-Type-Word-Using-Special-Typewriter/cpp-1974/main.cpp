/// Source : https://leetcode.com/problems/minimum-time-to-type-word-using-special-typewriter/
/// Author : liuyubobobo
/// Time   : 2021-08-21

#include <iostream>

using namespace std;


/// Linear Scan
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int minTimeToType(string word) {

        int res = 0;

        char prev = 'a';
        for(char c: word){
            int a = prev - 'a', b = c - 'a';
            int maxv = max(a, b), minv = min(a, b);
            res += min(maxv - minv, minv - maxv + 26);
            prev = c;
        }
        res += word.size();
        return res;
    }
};

int main() {

    cout << Solution().minTimeToType("abc") << endl;
    // 5

    return 0;
}
