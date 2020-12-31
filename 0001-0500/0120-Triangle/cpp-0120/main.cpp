/// Source : https://leetcode.com/problems/triangle/description/
/// Author : liuyubobobo
/// Time   : 2018-03-26

#include <iostream>
#include <vector>

using namespace std;

/// Dynamic Programming
/// Time Complexity: O(n^2)
/// Space Complexity: O(1)
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {

        int n = triangle.size();
        for(int i = 1 ; i < n ; i ++){

            triangle[i][0] += triangle[i-1][0];
            triangle[i][i] += triangle[i-1][i-1];
            for(int j = 1 ; j < i ; j ++)
                triangle[i][j] += min(triangle[i-1][j-1], triangle[i-1][j]);
        }

        return *min_element(triangle[n-1].begin(), triangle[n-1].end());
    }
};


int main() {

    vector<vector<int>> triangle = { {2},
                                     {3, 4},
                                     {6,5,7},
                                     {4,1,8,3}};
    cout << Solution().minimumTotal(triangle) << endl;
    // 11

    return 0;
}