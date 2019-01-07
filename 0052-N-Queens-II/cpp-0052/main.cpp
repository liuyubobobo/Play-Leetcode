/// Source : https://leetcode.com/problems/n-queens-ii/
/// Author : liuyubobobo
/// Time   : 2018-01-07

#include <iostream>
#include <vector>

using namespace std;


/// Basic Recursive
/// Time Complexity: O(n^n)
/// Space Complexity: O(n)
class Solution {
public:
    int totalNQueens(int n) {

        vector<int> row;
        vector<bool> col(n, false), dia1(2 * n - 1, false), dia2(2 * n - 1, false);

        return dfs(n, 0, row, col, dia1, dia2);
    }

private:
    int dfs(int n, int index, vector<int>& row,
            vector<bool>& col, vector<bool>& dia1, vector<bool>& dia2){

        if(index == n)
            return 1;

        int res = 0;
        for(int i = 0; i < n; i ++)
            if(!col[i] && !dia1[index + i] && !dia2[index - i + n - 1]){
                row.push_back(i);
                col[i] = true;
                dia1[index + i] = true;
                dia2[index - i + n - 1] = true;

                res += dfs(n, index + 1, row, col, dia1, dia2);

                col[i] = false;
                dia1[index + i] = false;
                dia2[index - i + n - 1] = false;
                row.pop_back();
            }
        return res;
    }
};


int main() {

    return 0;
}