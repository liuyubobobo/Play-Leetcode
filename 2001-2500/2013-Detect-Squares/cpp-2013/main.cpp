/// Source : https://leetcode.com/problems/detect-squares/
/// Author : liuyubobobo
/// Time   : 2021-09-18

#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;


/// Using Map
/// Time Complexity: init: O(1)
///                  add: O(1)
///                  count: O(n)
/// Space Cpmlexity: O(n)
class DetectSquares {

private:
    map<int, map<int, int>> points;

public:
    DetectSquares() {}

    void add(vector<int> point) {

        int x = point[0], y = point[1];
        points[x][y] ++;
    }

    int count(vector<int> point) {

        int x0 = point[0], y0 = point[1], res = 0;

        if(points.count(x0)){
            map<int, int>& yset = points[x0];
            for(const pair<int, int>& p: yset){

                int y1 = p.first;
                if(y1 == y0) continue;

                int s = abs(y0 - y1);
                int c1 = points[x0 - s][y0];
                int c2 = points[x0 - s][y1];
                res += p.second * c1 * c2;

                c1 = points[x0 + s][y0];
                c2 = points[x0 + s][y1];
                res += p.second * c1 * c2;
            }
        }
        return res;
    }
};


int main() {

    return 0;
}
