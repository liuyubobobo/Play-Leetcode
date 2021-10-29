/// Source : https://leetcode.com/problems/self-crossing/
/// Author : liuyubobobo
/// Time   : 2021-10-28

#include <iostream>
#include <vector>

using namespace std;


/// Geography
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {

private:
    typedef struct Point{
        long long x, y;
        Point(long long x, long long y) : x(x), y(y){}
    }Point;

    const int dirs[4][2] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};

public:
    bool isSelfCrossing(vector<int>& dis) {

        int n = dis.size();
        int L = 5;

        vector<pair<Point, Point>> segs;
        Point cur(0, 0);
        for(int i = 0; i < n; i ++){
            Point next(cur.x + dirs[i % 4][0] * dis[i], cur.y + dirs[i % 4][1] * dis[i]);
            segs.push_back({cur, next});

            for(int j = i - 2; j >= max(0, i - L); j --)
                if(intersect(segs[i].first, segs[i].second, segs[j].first, segs[j].second))
                    return true;

            cur = next;
        }
        return false;
    }

private:
    bool on_segment(Point p, Point q, Point r)
    {
        if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
            q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
            return true;
        return false;
    }

    int orientation(Point p, Point q, Point r)
    {
        long long val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
        if (val == 0) return 0; // collinear
        return (val > 0)? 1: 2; // clock or counterclock wise
    }

    bool intersect(Point p1, Point q1, Point p2, Point q2){

        int o1 = orientation(p1, q1, p2);
        int o2 = orientation(p1, q1, q2);
        int o3 = orientation(p2, q2, p1);
        int o4 = orientation(p2, q2, q1);

        if (o1 != o2 && o3 != o4)
            return true;

        if (o1 == 0 && on_segment(p1, p2, q1)) return true;
        if (o2 == 0 && on_segment(p1, q2, q1)) return true;
        if (o3 == 0 && on_segment(p2, p1, q2)) return true;
        if (o4 == 0 && on_segment(p2, q1, q2)) return true;
        return false;
    }
};


int main() {

    vector<int> dis1 = {2, 1, 1, 2};
    cout << Solution().isSelfCrossing(dis1) << endl;
    // 1

    vector<int> dis2 = {3, 3, 4, 2, 2};
    cout << Solution().isSelfCrossing(dis2) << endl;
    // 0

    return 0;
}
