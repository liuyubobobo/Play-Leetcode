/// Source : https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
/// Author : liuyubobobo
/// Time   : 2018-11-13

#include <iostream>
#include <vector>
#include <queue>
#include <cassert>

using namespace std;


/// Using Binary Search
/// Time Complexity: O(m * n * log(max - min))
/// Space Complexity: O(1)
class Solution {

private:
    int m, n;

public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {

        m = matrix.size();
        n = matrix[0].size();

        int l = matrix[0][0], h = matrix[m - 1][n - 1];
        while(l < h){
            int mid = (l + h) / 2;
            int rank = get_rank(matrix, mid);
            if(rank >= k)
                h = mid;
            else
                l = mid + 1;
        }

        return l;
    }

private:
    int get_rank(const vector<vector<int>>& matrix, int target){

        int res = 0;
        for(int i = 0; i < m && matrix[i][0] <= target; i ++)
            for(int j = 0; j < n && matrix[i][j] <= target; j ++)
                res ++;
        return res;
    }
};


int main() {

    vector<vector<int>> matrix1 = {{-5}};
    cout << Solution().kthSmallest(matrix1, 1) << endl;
    // -5

    vector<vector<int>> matrix2 = {
            {1,  5,  9},
            {10, 11, 13},
            {12, 13, 15}
    };
    cout << Solution().kthSmallest(matrix2, 8) << endl;
    // 13

    vector<vector<int>> matrix3 = {
            {1,  3,  5},
            {6,  7,  12},
            {11, 14, 14}
    };
    cout << Solution().kthSmallest(matrix3, 3) << endl;
    // 5

    vector<vector<int>> matrix4 = {
            {1,  3,  5},
            {6,  7,  12},
            {11, 14, 14}
    };
    cout << Solution().kthSmallest(matrix4, 6) << endl;
    // 11

    return 0;
}