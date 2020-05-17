/// Source : https://leetcode.com/problems/maximum-number-of-darts-inside-of-a-circular-dartboard/
/// Author : liuyubobobo
/// Time   : 2020-05-16

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


/// Brute Force + Greedy
/// Time Complexity: O(n^3)
/// Space Complexity: O(1)
class Solution {

private:
    double e = 1e-6;

public:
    int numPoints(vector<vector<int>>& points, int r) {

        int res = 1;
        for(int i = 0; i < points.size(); i ++)
            for(int j = i + 1; j < points.size(); j ++){

                double x1 = points[i][0], y1 = points[i][1],
                       x2 = points[j][0], y2 = points[j][1];
                double x0 = (x1 + x2) / 2, y0 = (y1 + y2) / 2;
                double d = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
                double h = sqrt(r * r - d * d / 4.0);

                double xc = x0 - h * (y2 - y1) / d, yc = y0 - h * (x1 - x2) / d;
                res = max(res, get(points, xc, yc, r));

                double xd = x0 + h * (y2 - y1) / d, yd = y0 + h * (x1 - x2) / d;
                res = max(res, get(points, xd, yd, r));
            }
        return res;
    }

private:
    int get(const vector<vector<int>>& points, double x, double y, double r){

        int res = 0;
        for(const vector<int>& p: points)
            if((p[0] - x) * (p[0] - x) + (p[1] - y) * (p[1] - y) <= r * r + e)
                res ++;
        return res;
    }
};


int main() {

    vector<vector<int>> points1 = {{-2,0},{2,0},{0,2},{0,-2}};
    cout << Solution().numPoints(points1, 2) << endl;
    // 4

    vector<vector<int>> points2 = {{-3,0},{3,0},{2,6},{5,4},{0,9},{7,8}};
    cout << Solution().numPoints(points2, 5) << endl;
    // 5

    vector<vector<int>> points3 = {{1,2},{3,5},{1,-1},{2,3},{4,1},{1,3}};
    cout << Solution().numPoints(points3, 2) << endl;
    // 4

    vector<vector<int>> points4 = {{4,-4},{-2,0},{0,2},{-3,1},{2,3},{2,4},{1,1}};
    cout << Solution().numPoints(points4, 3) << endl;
    // 6

    return 0;
}
