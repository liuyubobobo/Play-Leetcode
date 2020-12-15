/// Source : https://leetcode-cn.com/problems/you-le-yuan-de-mi-gong/
/// Author : liuyubobobo
/// Time   : 2020-05-01

#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;


/// Polar Angle Sorting
/// Actucally same thoughts to Graham Scan
/// Time Complexity: O(n^2*logn)
/// Space Complexity: O(n)
class Solution {
public:
    vector<int> visitOrder(vector<vector<int>>& points, string direction) {

        map<vector<int>, int> pointsToIndex;
        for(const vector<int>& p: points) pointsToIndex[p] = pointsToIndex.size();

        set<vector<int>> left(points.begin(), points.end());
        vector<int> res;
        int cur = pointsToIndex.begin()->second;
        res.push_back(cur);
        left.erase(points[cur]);
        for(char c: direction){

            vector<vector<int>> vec;
            for(const vector<int>& p: left) vec.push_back(p);
            for(vector<int>& p: vec) p[0] -= points[cur][0], p[1] -= points[cur][1];
            sort(vec.begin(), vec.end(), [](const vector<int>& p1, const vector<int>& p2){
                return p1[0] * (p2[1] - p1[1]) - p1[1] * (p2[0] - p1[0]) > 0;
            });

            if(c == 'L')
                cur = pointsToIndex[{vec[0][0] + points[cur][0], vec[0][1] + points[cur][1]}];
            else
                cur = pointsToIndex[{vec.back()[0] + points[cur][0], vec.back()[1] + points[cur][1]}];

            res.push_back(cur);
            left.erase(points[cur]);
        }
        res.push_back(pointsToIndex[*left.begin()]);
//        for(int i: res) cout << i << " "; cout << endl;
        return res;
    }
};


void print_vec(const vector<int>& v){
    for(int e: v) cout << e << " "; cout << endl;
}

int main() {

    vector<vector<int>> points1 = {{1,1},{1,4},{3,2},{2,1}};
    print_vec(Solution().visitOrder(points1, "LL"));

    vector<vector<int>> points2 = {{1,3},{2,4},{3,3},{2,1}};
    print_vec(Solution().visitOrder(points2, "LR"));

    vector<vector<int>> points3 = {{3,5},{4,5},{9,1},{5,6}, {4, 2}};
    print_vec(Solution().visitOrder(points3, "RLR"));

    return 0;
}
