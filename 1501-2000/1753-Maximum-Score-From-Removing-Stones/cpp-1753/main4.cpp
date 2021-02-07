/// Source : https://leetcode.com/problems/maximum-score-from-removing-stones/
/// Author : liuyubobobo
/// Time   : 2021-02-06

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


/// Mathematics
/// Time Complexity: O(1)
/// Space Complexity: O(1)
class Solution {
public:
    int maximumScore(int a, int b, int c) {

        if(a >= b + c) return b + c;
        if(b >= a + c) return a + c;
        if(c >= a + b) return a + b;
        return (a + b + c) / 2;
    }
};


int main() {

    cout << Solution().maximumScore(2, 4, 6) << endl;
    // 6

    cout << Solution().maximumScore(4, 4, 6) << endl;
    // 7

    cout << Solution().maximumScore(1, 8, 8) << endl;
    // 8

    return 0;
}
