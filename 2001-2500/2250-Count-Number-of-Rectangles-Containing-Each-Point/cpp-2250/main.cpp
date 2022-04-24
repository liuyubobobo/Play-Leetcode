/// Source : https://leetcode.com/problems/count-number-of-rectangles-containing-each-point/
/// Author : liuyubobobo
/// Time   : 2022-04-23

#include <iostream>
#include <vector>

using namespace std;


/// Binary Search
/// Time Complexity: O(|rec|log|rec| + |point|log|rec|)
/// Space Complexity: O(|rec|)
class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {

        vector<vector<int>> h_rec(101);
        for(const vector<int>& rec: rectangles){
            int l = rec[0], h = rec[1];
            h_rec[h].push_back(l);
        }

        for(int i = 0; i <= 100; i ++) sort(h_rec[i].begin(), h_rec[i].end());

        vector<int> res(points.size());
        for(int i = 0; i < points.size(); i ++){
            int x = points[i][0], y = points[i][1];
            int tres = 0;
            for(int h = y; h <= 100; h ++){
                if(h_rec.empty()) continue;
                auto iter = lower_bound(h_rec[h].begin(), h_rec[h].end(), x);
                if(iter != h_rec[h].end()){
                    int index = iter - h_rec[h].begin();
                    tres += h_rec[h].size() - index;
                }
            }
            res[i] = tres;
        }
        return res;
    }
};


int main() {

    vector<vector<int>> rectangles1 = {{1, 2}, {2, 3}, {2, 5}};
    vector<vector<int>> points1 = {{2, 1}, {1, 4}};
    Solution().countRectangles(rectangles1, points1);

    return 0;
}
