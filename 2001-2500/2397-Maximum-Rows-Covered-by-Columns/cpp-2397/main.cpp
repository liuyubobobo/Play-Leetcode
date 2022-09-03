/// Source : https://leetcode.com/problems/maximum-rows-covered-by-columns/
/// Author : liuyubobobo
/// Time   : 2022-09-03

#include <iostream>
#include <vector>

using namespace std;


/// Backtrack
/// Time Complexity: O(C(C, cols) * R * C)
/// Space Complexity: O(C)
class Solution {

public:
    int maximumRows(vector<vector<int>>& mat, int cols) {

        int R = mat.size(), C = mat[0].size();

        int res = 0;
        vector<int> v(C, 0);
        dfs(R, C, mat, cols, 0, v, res);
        return res;
    }

private:
    void dfs(int R, int C, const vector<vector<int>>& mat,
             int k, int start, vector<int>& v, int& res){

        if(k == 0){
            res = max(res, get_rows(R, C, mat, v));
            return;
        }

        for(int i = start; i <= C - k; i ++){
            v[i] = 1;
            dfs(R, C, mat, k - 1, i + 1, v, res);
            v[i] = 0;
        }
    }

    int get_rows(int R, int C, const vector<vector<int>>& mat, const vector<int>& col){

        int res = 0;
        for(int i = 0; i < R; i ++)
            res += ok(C, mat[i], col);
        return res;
    }

    bool ok(int n, const vector<int>& v1, const vector<int>& v2){
        for(int i = 0; i < n; i ++)
            if(v1[i] == 1 && v2[i] == 0) return false;
        return true;
    }
};


int main() {

    return 0;
}
