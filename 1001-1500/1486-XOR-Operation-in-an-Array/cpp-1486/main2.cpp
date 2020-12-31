/// Source : https://leetcode.com/problems/xor-operation-in-an-array/
/// Author : liuyubobobo
/// Time   : 2020-06-24

#include <iostream>
#include <vector>

using namespace std;


/// Mathematics
/// Time Complexity: O(1)
/// Space Complexity: O(1)
class Solution {
public:
    int xorOperation(int n, int start) {
        return 2 * f(n, start / 2) + ((start % 2 == 0 || n % 2 == 0) ? 0 : 1);
    }

private:
    int f(int n, int start){
        if(start % 2 == 0)
            return n % 2 ? ((n / 2) & 1) ^ (start + n - 1) : ((n / 2) & 1);
        return f(n + 1, start - 1) ^ (start - 1);
    }
};


int main() {

    cout << Solution().xorOperation(3, 2) << endl;

    return 0;
}
