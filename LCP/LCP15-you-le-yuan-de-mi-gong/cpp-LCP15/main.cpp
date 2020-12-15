/// Source : https://leetcode-cn.com/problems/you-le-yuan-de-mi-gong/
/// Author : liuyubobobo
/// Time   : 2020-05-01

#include <iostream>
#include <vector>
#include <map>

using namespace std;


/// Using Convex Hull
/// Time Complexity: O(n^2*logn)
/// Space Complexity: O(n)
class Solution {
public:
    vector<int> visitOrder(vector<vector<int>>& points, string direction) {

        int n = points.size();

        map<vector<int>, int> pointsToIndex;
        for(const vector<int>& p: points) pointsToIndex[p] = pointsToIndex.size();

        vector<int> res = {pointsToIndex.begin()->second};
        int cur = res[0];
        for(char c: direction){
            vector<int> hull = convex_hull(pointsToIndex, points);
            pointsToIndex.erase(points[cur]);
//            cout << "hull "; for(int i: hull) cout << i << " "; cout << endl;
            int curpos;
            for(curpos = 0; curpos < n; curpos ++)  if(hull[curpos] == cur) break;

            if(c == 'L') cur = hull[(curpos + 1) % n];
            else cur = hull[(curpos - 1 + hull.size()) % hull.size()];

            res.push_back(cur);
        }
        pointsToIndex.erase(points[cur]);
        res.push_back(pointsToIndex.begin()->second);
//        for(int i: res) cout << i << " "; cout << endl;
        return res;
    }

private:
    vector<int> convex_hull(map<vector<int>, int>& pointsToIndex, const vector<vector<int>>& points){

        vector<int> res;
        for(map<vector<int>, int>::iterator iter = pointsToIndex.begin();
            iter != pointsToIndex.end(); iter ++){

            while(res.size() >= 2 && cross(points[res[res.size() - 2]], points[res.back()], iter->first) < 0)
                res.pop_back();
            res.push_back(iter->second);
        }

        map<vector<int>, int>::reverse_iterator riter = pointsToIndex.rbegin();
        for(riter ++; riter != pointsToIndex.rend(); riter ++){
            while(res.size() >= 2 && cross(points[res[res.size() - 2]], points[res.back()], riter->first) < 0)
                res.pop_back();
            res.push_back(riter->second);
        }

        res.pop_back();
        return res;
    }

    int cross(const vector<int>& p1, const vector<int>& p2, const vector<int>& p3){
        return (p2[0] - p1[0]) * (p3[1] - p2[1]) - (p3[0] - p2[0]) * (p2[1] - p1[1]);
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
