/// Source : https://leetcode.com/problems/erect-the-fence/
/// Author : liuyubobobo
/// Time   : 2020-05-01

#include <iostream>
#include <vector>

using namespace std;


/// Graham Scan - One Pass
/// Time Complexity: O(nlogn + n)
/// Space Complexity: O(1)

vector<int> start;

int cross_value(const vector<int>& p1, const vector<int>& p2, const vector<int>& p3){
    int a = p2[0] - p1[0], b = p2[1] - p1[1];
    int c = p3[0] - p2[0], d = p3[1] - p2[1];
    return a * d - b * c;
}

int distance_square(const vector<int>& p1, const vector<int>& p2){
    return (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]);
}

bool cmp(const vector<int>& p1, const vector<int>& p2){
    int det = cross_value(start, p1, p2);
    if(det == 0) return distance_square(start, p1) < distance_square(start, p2);
    return det > 0;
}

class Solution {
public:
    vector<vector<int>> outerTrees(vector<vector<int>>& points) {

        if(points.size() <= 3) return points;

        int leftmost = 0;
        for(int i = 1; i < points.size(); i ++)
            if(points[i][0] < points[leftmost][0] ||
               (points[i][0] == points[leftmost][0] && points[i][1] < points[leftmost][1]))
                leftmost = i;
        swap(points[0], points[leftmost]);
        start = points[0];

        sort(points.begin() + 1, points.end(), cmp);

//        for(const vector<int>& p: points)
//            cout << "(" << p[0] << "," << p[1] << ") "; cout << endl;

        for(int i = points.size() - 2; i >= 0; i --)
            if(cross_value(points[0], points.back(), points[i]) != 0){
                for(int l = i + 1, r = points.size() - 1; l < r; l ++, r --)
                    swap(points[l], points[r]);
                break;
            }

        vector<vector<int>> res = {points[0], points[1]};
        for(int i = 2; i < points.size(); i ++){
            while(res.size() >= 2 && cross_value(res[res.size() - 2], res.back(), points[i]) < 0)
                res.pop_back();
            res.push_back(points[i]);
        }
        return res;
    }
};


void print_vec(const vector<vector<int>>& vec){
    for(const vector<int>& p: vec) cout << "(" << p[0] << "," << p[1] << ")"; cout << endl;
}

int main() {

    vector<vector<int>> points = {{1,1},{2,2},{2,0},{2,4},{3,3},{4,2}};
    print_vec(Solution().outerTrees(points));

    return 0;
}
