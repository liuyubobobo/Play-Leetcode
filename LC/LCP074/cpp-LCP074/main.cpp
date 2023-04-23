/// Source : https://leetcode.cn/problems/xepqZ5/
/// Author : liuyubobobo
/// Time   : 2023-04-22

#include <iostream>
#include <vector>
#include <set>

using namespace std;


/// Brute Force
/// Time Complexity: O(n^3)
/// Space Complexity: O(n^2)
class Solution {
public:
    int fieldOfGreatestBlessing(vector<vector<int>>& forceField) {

        int n = forceField.size();
        vector<vector<long long>> llforceField(n, vector<long long>(3));
        for(int i = 0; i < n; i ++)
            for(int j = 0; j < 3; j ++) llforceField[i][j] = forceField[i][j] * 2ll;

        set<pair<long long, long long>> points;
        for(int i = 0; i < n; i ++)
            for(int j = i + 1; j < n; j ++)
                get_points(points, llforceField[i], llforceField[j]);

        int res = 1;
        for(const pair<long long, long long>& p: points)
            res = max(res, in_rec(p.first, p.second, llforceField));
        return res;
    }

private:
    int in_rec(long long x, long long y, const vector<vector<long long>>& f){
        int res = 0;
        for(const vector<long long>& ff: f) res += in_rec(x, y, ff);
        return res;
    }

    int in_rec(long long x, long long y, const vector<long long>& f){
        long long x0 = f[0] - f[2] / 2, y0 = f[1] - f[2] / 2, len = f[2];
        return x0 <= x && x <= x0 + len && y0 <= y && y <= y0 + len;
    }

    void get_points(set<pair<long long, long long>>& points, const vector<long long>& f1, const vector<long long>& f2) {

        long long x1 = f1[0] - f1[2] / 2, y1 = f1[1] - f1[2] / 2, len1 = f1[2];
        long long x2 = f2[0] - f2[2] / 2, y2 = f2[1] - f2[2] / 2, len2 = f2[2];

        get_points(x1, y1, x1 + len1, y1, x2, y2, len2, points);
        get_points(x1 + len1, y1, x1 + len1, y1 + len1, x2, y2, len2, points);
        get_points(x1 + len1, y1 + len1, x1, y1 + len1, x2, y2, len2, points);
        get_points(x1, y1 + len1, x1, y1, x2, y2, len2, points);

//        get_points(x2, y2, x2 + len2, y2, x1, y1, len1, points);
//        get_points(x2 + len2, y2, x2 + len2, y2 + len2, x1, y1, len1, points);
//        get_points(x2 + len2, y2 + len2, x2, y2 + len2, x1, y1, len1, points);
//        get_points(x2, y2 + len2, x2, y2, x1, y1, len1, points);
    }

    void get_points(long long x0, long long y0, long long x1, long long y1,
                    long long x, long long y, long long len,
                    set<pair<long long, long long>>& points) {

        if(x0 == x1) {
            if(y0 > y1) swap(y0, y1); // y0 <= y1
            if(x <= x0 && x0 <= x + len) {
                if(y0 <= y){
                    if(y1 >= y) points.insert({x0, y});
                    if(y1 <= y + len) points.insert({x0, y1});
                    else if(y1 >= y + len) points.insert({x0, y + len});
                }
                else if(y0 <= y + len) {
                    points.insert({x0, y0});
                    if(y1 <= y + len) points.insert({x0, y1});
                    else if(y1 >= y + len) points.insert({x0, y + len});
                }
            }
        }
        if(y0 == y1){
            if(x0 > x1) swap(x0, x1); // x0 <= x1
            if(y <= y0 && y0 <= y + len) {
                if(x0 <= x){
                    if(x1 >= x) points.insert({x, y0});
                    if(x1 <= x + len) points.insert({x1, y0});
                    else if(x1 >= x + len) points.insert({x + len, y0});
                }
                else if(x0 <= x + len) {
                    points.insert({x0, y0});
                    if(x1 <= x + len) points.insert({x1, y0});
                    else if(x1 >= x + len) points.insert({x + len, y0});
                }
            }
        }
    }
};


int main() {

    return 0;
}
