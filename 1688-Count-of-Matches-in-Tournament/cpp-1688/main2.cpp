/// Source : https://leetcode.com/problems/count-of-matches-in-tournament/
/// Author : liuyubobobo
/// Time   : 2020-12-12

#include <iostream>
#include <vector>

using namespace std;


/// Mathematics
/// Time Complexity: O(logn)
/// Space Complexity: O(1)
class Solution {
public:
    int numberOfMatches(int n) {

        return n - 1;
    }
};


int main() {

    cout << Solution().numberOfMatches(7) << endl;
    // 6

    return 0;
}
