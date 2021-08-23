#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {

        int res = 0, x = points[0][0], y = points[0][1];
        for(int i = 1; i < points.size(); i ++)
            res += max(abs(points[i][0] - x), abs(points[i][1] - y)),
            x = points[i][0], y = points[i][1];
        return res;
    }
};


int main() {

    return 0;
}