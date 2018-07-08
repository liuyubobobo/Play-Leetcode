/// Source : https://leetcode.com/problems/transpose-matrix/description/
/// Author : liuyubobobo
/// Time   : 2018-07-07

#include <iostream>
#include <vector>

using namespace std;

/// Ad-Hoc
/// Time Complexity: O(m*n)
/// Space Complexity: O(1)
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {

        int m = A.size();
        int n = A[0].size();

        vector<vector<int>> res(n, vector<int>(m, 0));
        for(int i = 0 ; i < m ; i ++)
            for(int j = 0 ; j < n ; j ++)
                res[j][i] = A[i][j];
        return res;
    }
};


int main() {

    return 0;
}