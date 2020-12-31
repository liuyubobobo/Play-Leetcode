/// Source : https://leetcode.com/problems/range-addition-ii/description/
/// Author : liuyubobobo
/// Time   : 2017-10-28

#include <iostream>
#include <vector>

using namespace std;

/// Time Complexity: O(len(ops))
/// Space Complexity: O(1)
class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {

        int x = m, y = n;
        for(vector<int> op: ops){
            x = min(x, op[0]);
            y = min(y, op[1]);
        }

        return x * y;
    }
};

int main() {

    int m = 3, n = 3;
    int ops[2][2] = {{2, 2}, {3, 3}};
    vector<vector<int>> vec;
    for(int i = 0 ; i < 2 ; i ++)
        vec.push_back(vector<int>(ops[i], ops[i] + sizeof(ops[i])/sizeof(int)));
    cout << Solution().maxCount(m, n, vec) << endl;

    return 0;
}