/// Source : https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
/// Author : liuyubobobo
/// Time   : 2018-11-13
/// Updated: 2022-08-02

#include <iostream>
#include <vector>
#include <queue>
#include <cassert>

using namespace std;


/// Using Binary Search
/// pay attention to the edge case when l + h is negative,
/// normally in binary search, we are searching for index, so l and h are both non-negative
/// but when l and h can be negative, we need to do a special discuss
/// See line 36 and test case 5 for details
///
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
            int sum = l + h, mid = sum / 2;
            if(sum < 0 && sum % 2) mid --;

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

    vector<vector<int>> matrix5 = {
            {-5, -4},
            {-5, -4}
    };
    cout << Solution().kthSmallest(matrix5, 2) << endl;
    // -5

    vector<vector<int>> matrix6 = {
            {1, 5, 9},
            {10, 11, 13},
            {12, 13, 15}
    };
    cout << Solution().kthSmallest(matrix6, 8) << endl;
    // 13

    return 0;
}