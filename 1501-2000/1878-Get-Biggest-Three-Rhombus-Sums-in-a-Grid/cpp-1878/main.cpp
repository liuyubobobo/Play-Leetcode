/// Source : https://leetcode.com/problems/get-biggest-three-rhombus-sums-in-a-grid/
/// Author : liuyubobobo
/// Time   : 2021-06-10

#include <iostream>
#include <vector>
#include <set>

using namespace std;


/// PreSum
/// Time Complexity: O(m * n)
/// Space Complexity: O(m * n)
class Solution {

private:
    int m, n;

public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {

        m = grid.size(), n = grid[0].size();
        vector<vector<int>> A(m + 2, vector<int>(n + 2, 0)), B = A;

        for(int i = 0; i < m; i ++)
            for(int j = 0; j < n; j ++) {
                A[i + 1][j + 1] = grid[i][j] + A[i][j];
                B[i + 1][j + 1] = grid[i][j] + B[i][j + 2];
            }

//        cout << "grid : " << endl;
//        for(const vector<int>& r: grid){
//            for(int e: r) cout << e << "\t"; cout << endl;
//        }
//
//        cout << "A : " << endl;
//        for(const vector<int>& r: A){
//            for(int e: r) cout << e << "\t"; cout << endl;
//        }
//
//        cout << "B : " << endl;
//        for(const vector<int>& r: B){
//            for(int e: r) cout << e << "\t"; cout << endl;
//        }

        set<int> set;
        for(int i = 0; i < m; i ++)
            for(int j = 0; j < n; j ++){
                set.insert(grid[i][j]);

                for(int sz = 1; in_area(i-sz,j+sz) && in_area(i+sz,j+sz) && in_area(i,j+2*sz);sz++){
                    int res = A[i + sz + 1][j + sz + 1] - A[i][j];
                    res += A[i + 1][j + 2 * sz + 1] - A[i - sz][j + sz];
                    res += B[i - 1 + 1][j + 1 + 1] - B[i - sz + 1][j + sz + 1];
                    res += B[i + sz - 1 + 1][j + sz + 1 + 1] - B[i + 1][j + 2 * sz + 1];
//                    res -= grid[i][j] + grid[i - sz][j + sz] + grid[i][j + 2 * sz] + grid[i + sz][j + sz];
                    set.insert(res);
//                    cout << i << "," << j << "," << sz << " : " << res << endl;
                }
            }

        vector<int> res;
        while(!set.empty() && res.size() < 3){
            res.push_back(*set.rbegin());
            set.erase(res.back());
        }
        return res;
    }

private:
    bool in_area(int x, int y){
        return x >= 0 && x < m && y >= 0 && y < n;
    }
};


void print_vector(const vector<int>& v){
    for(int e: v) cout << e << " "; cout << endl;
}

int main() {

    vector<vector<int>> grid1 = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
    };
    print_vector(Solution().getBiggestThree(grid1));
    // 20, 9, 8

    vector<vector<int>> grid2 = {
            {3,4,5,1,3},
            {3,3,4,2,3},
            {20,30,200,40,10},
            {1,5,5,4,1},
            {4,3,2,2,5}
    };
    print_vector(Solution().getBiggestThree(grid2));
    // 228, 216, 211

    vector<vector<int>> grid3 = {{7, 7, 7}};
    print_vector(Solution().getBiggestThree(grid3));
    // 7

    vector<vector<int>> grid4 ={
            {20,17,9,13,5,2,9,1,5},
            {14,9,9,9,16,18,3,4,12},
            {18,15,10,20,19,20,15,12,11},
            {19,16,19,18,8,13,15,14,11},
            {4,19,5,2,19,17,7,2,2}
    };
    print_vector(Solution().getBiggestThree(grid4));
    // 107, 103, 102

    return 0;
}
