/// Source : https://leetcode.com/problems/xor-operation-in-an-array/
/// Author : liuyubobobo
/// Time   : 2020-06-20

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int xorOperation(int n, int start) {

        int res = 0;
        for(int i = 0; i < n; i ++)
            res ^= start + 2 * i;
        return res;
    }
};


int main() {

    cout << Solution().xorOperation(3, 2) << endl;

    return 0;
}
