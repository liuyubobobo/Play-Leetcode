/// Source : https://leetcode.com/problems/minimum-area-rectangle/
/// Author : liuyubobobo
/// Time   : 2018-11-10

#include <iostream>
#include <set>
#include <vector>

using namespace std;


/// Using Set to store every point
/// Time Complexity: O(n^2)
/// Space Complexity: O(n)
class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {

        set<pair<int, int>> set;
        for(const vector<int>& point: points)
            set.insert(make_pair(point[0], point[1]));

        int min_area = INT_MAX;
        for(int i = 0; i < points.size(); i ++)
            for(int j = i + 1; j < points.size(); j ++){
                pair<int, int> p1 = make_pair(points[i][0], points[j][1]);
                pair<int, int> p2 = make_pair(points[j][0], points[i][1]);
                if(set.count(p1) && set.count(p2) &&
                    points[i][0] != points[j][0] && points[i][1] != points[j][1])
                    min_area = min(min_area,
                                   abs(points[i][0] - points[j][0]) * abs(points[i][1] - points[j][1]));
            }
        return min_area == INT_MAX ? 0 : min_area;
    }
};

int main() {

    return 0;
}