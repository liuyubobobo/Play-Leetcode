/// Source : https://leetcode.com/problems/minimum-area-rectangle/
/// Author : liuyubobobo
/// Time   : 2018-11-11

#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;


/// Using HashSet to store every point
/// Using Integer to represent evey point
///
/// Time Complexity: O(n^2)
/// Space Complexity: O(n)
class Solution {

private:
    const int N = 40001;

public:
    int minAreaRect(vector<vector<int>>& points) {

        unordered_set<int> set;
        for(const vector<int>& point: points)
            set.insert(point[0] * N + point[1]);

        int min_area = INT_MAX;
        for(int i = 0; i < points.size(); i ++)
            for(int j = i + 1; j < points.size(); j ++){
                int p1 = points[i][0] * N + points[j][1];
                int p2 = points[j][0] * N + points[i][1];
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