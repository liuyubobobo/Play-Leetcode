/// Source : https://leetcode.com/problems/valid-boomerang/
/// Author : liuyubobobo
/// Time   : 2019-05-04

#include <iostream>
#include <vector>

using namespace std;


/// Calculate Slope
/// Time Compelxity: O(1)
/// Space Complexity: O(1)
class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {

        if(points[0] == points[1] || points[1] == points[2])
            return false;

        int a = points[1][0] - points[0][0], c = points[2][0] - points[1][0],
            b = points[1][1] - points[0][1], d = points[2][1] - points[1][1];
        return a * d != b * c;
    }
};


int main() {

    vector<vector<int>> points1 = {{1, 1}, {2, 3}, {3, 2}};
    cout << Solution().isBoomerang(points1) << endl;
    // true

    vector<vector<int>> points2 = {{1, 1}, {2, 2}, {3, 3}};
    cout << Solution().isBoomerang(points2) << endl;
    // false

    vector<vector<int>> points3 = {{0, 0}, {1, 1}, {1, 1}};
    cout << Solution().isBoomerang(points3) << endl;
    // false

    vector<vector<int>> points4 = {{80, 32}, {46, 32}, {59, 32}};
    cout << Solution().isBoomerang(points3) << endl;
    // false

    return 0;
}