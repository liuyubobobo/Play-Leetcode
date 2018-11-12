/// Source : https://leetcode.com/problems/minimum-area-rectangle/
/// Author : liuyubobobo
/// Time   : 2018-11-12

#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;


/// Using TreeMap to store every point in column
/// Using a "code" to record every height of each column
/// Tricky in my opinion :-)
///
/// Time Complexity: O(n^2)
/// Space Complexity: O(n)
class Solution {

private:
    const int N = 40001;

public:
    int minAreaRect(vector<vector<int>>& points) {

        map<int, vector<int>> pts;
        for(const vector<int>& point: points)
            pts[point[0]].push_back(point[1]);

        for(const pair<int, vector<int>>& col: pts)
            sort(pts[col.first].begin(), pts[col.first].end());

        unordered_map<int, int> last; // code -> x
        int min_area = INT_MAX;
        for(const pair<int, vector<int>>& col: pts){

            for(int i = 0; i < col.second.size(); i ++)
                for(int j = i + 1; j < col.second.size(); j ++){
                    int code = col.second[i] * N + col.second[j];
                    if(last.count(code))
                        min_area = min(min_area, (col.first - last[code]) * abs(col.second[i] - col.second[j]));
                    last[code] = col.first;
                }
        }
        return min_area == INT_MAX ? 0 : min_area;
    }
};


int main() {

    return 0;
}