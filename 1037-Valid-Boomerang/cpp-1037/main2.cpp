/// Source : https://leetcode.com/problems/valid-boomerang/
/// Author : liuyubobobo
/// Time   : 2019-05-18

#include <iostream>
#include <vector>

using namespace std;


/// Calculate Cross Multiplication
/// Time Compelxity: O(1)
/// Space Complexity: O(1)
class Solution {
public:
    bool isBoomerang(vector<vector<int>>& p) {
        int a = p[1][0] - p[0][0], b = p[1][1] - p[0][1],
            c = p[2][0] - p[1][0], d = p[2][1] - p[1][1];
        return a * d - b * c != 0;
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