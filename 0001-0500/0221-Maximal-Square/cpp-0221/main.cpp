/// Source : https://leetcode.com/problems/maximal-square/
/// Author : liuyubobobo
/// Time   : 2020-01-04

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O(m * n * m * n * min(m, n))
/// Space Complexity: O(1)
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {

        int res = 0;
        for(int i = 0; i < matrix.size(); i ++)
            for(int j = 0; j < matrix[i].size(); j ++)
                if(matrix[i][j] == '1'){
                    for(int len = 1; i + len <= matrix.size() && j + len <= matrix[i].size(); len ++)
                        if(ok(matrix, i, j, len)) res = max(res, len * len);
                        else break;
                }
        return res;
    }

private:
    bool ok(const vector<vector<char>>& matrix, int x, int y, int len){

        for(int i = x; i < x + len; i ++)
            for(int j = y; j < y + len; j ++)
                if(matrix[i][j] == '0') return false;
        return true;
    }
};


int main() {

    return 0;
}
