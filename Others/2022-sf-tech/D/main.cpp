/// Source : https://leetcode.cn/contest/sf-tech/problems/uWWzsv/
/// Author : liuyubobobo
/// Time   : 2022-06-23

#include <iostream>
#include <vector>
#include <complex>

#define X real()
#define Y imag()

using namespace std;


typedef double C;
typedef complex<C> P;

const double EPS = 1e-6;

/// Cross Product
/// Time Complexity: O(t)
/// Space Complexity: O(1)
C cross_product(P a, P b){
    return (conj(a) * b).Y; // a.X * b.Y - b.X * a.Y
}

bool is_zero(C x){
    return abs(x) < EPS;
}
// 1  : left
// 0  : touch
// -1 : right
int test_point_loc(P p, P s1, P s2){
    C res = cross_product(p - s1, p - s2);
    if(is_zero(res)) return 0;
    return res > 0 ? 1 : -1;
}

// 0  : on boundary
// 1  : intersection
// -1 : no intersection
int intersect(P p1, P p2, P p3, P p4){

    C x1 = p1.X, y1 = p1.Y, x2 = p2.X, y2 = p2.Y, x3 = p3.X, y3 = p3.Y, x4 = p4.X, y4 = p4.Y;

    int loc1 = test_point_loc(p1, p3, p4), loc2 = test_point_loc(p2, p3, p4);
    int loc3 = test_point_loc(p3, p1, p2), loc4 = test_point_loc(p4, p1, p2);

    if(loc1 == 0 && min(x3, x4) <= x1 && x1 <= max(x3, x4)
       && min(y3, y4) <= y1 && y1 <= max(y3, y4)) return 0;

    if(loc2 == 0 && min(x3, x4) <= x2 && x2 <= max(x3, x4)
       && min(y3, y4) <= y2 && y2 <= max(y3, y4)) return 0;

    if(loc3 == 0 && min(x1, x2) <= x3 && x3 <= max(x1, x2)
       && min(y1, y2) <= y3 && y3 <= max(y1, y2)) return 0;

    if(loc4 == 0 && min(x1, x2) <= x4 && x4 <= max(x1, x2)
       && min(y1, y2) <= y4 && y4 <= max(y1, y2)) return 0;

    if(!loc1 || !loc2 || !loc3 || !loc4) return -1;

    if(loc1 * loc2 > 0 || loc3 * loc4 > 0) return -1;
    return 1;
}

//long long gcd(long long a, long long b)
//{
//    if(a > b) swap(a, b);
//    if (a == 0) return b;
//    return gcd(b % a, a);
//}

int in_polygon(int n, const vector<P>& polygon, P p){

    for(int i = 1; i < n; i ++){
        int loc = test_point_loc(p, polygon[i], polygon[i - 1]);
        if(loc == 0 && min(polygon[i].X, polygon[i - 1].X) <= p.X && p.X <= max(polygon[i].X, polygon[i - 1].X)
           && min(polygon[i].Y, polygon[i - 1].Y) <= p.Y && p.Y <= max(polygon[i].Y, polygon[i - 1].Y))
            return 0;
    }

    int loc = test_point_loc(p, polygon[n - 1], polygon[0]);
    if(loc == 0 && min(polygon[n - 1].X, polygon[0].X) <= p.X && p.X <= max(polygon[n - 1].X, polygon[0].X)
       && min(polygon[n - 1].Y, polygon[0].Y) <= p.Y && p.Y <= max(polygon[n - 1].Y, polygon[0].Y))
        return 0;

    // 保证 p2.X - p1.X 和 p2.Y - p1.Y 互质，
    double INF = 1e9 + 7;

    P p1 = p, p2 = {p.X + INF, p.Y + 1};
    int cnt = 0;
    for(int i = 1; i < n; i ++)
        cnt += intersect(p1, p2, polygon[i], polygon[i - 1]) >= 0;
    cnt += intersect(p1, p2, polygon[n - 1], polygon[0]) >= 0;

    return (cnt & 1) ? -1 : 1;
}

class Solution {
public:
    bool isPointInPolygon(double x, double y, vector<double>& coords) {

        vector<P> polygon;
        for(int i = 0; i < coords.size(); i += 2)
            polygon.push_back({coords[i], coords[i + 1]});

        P p = {x, y};
        return in_polygon(polygon.size(), polygon, p) < 0;
    }
};

int main() {

    return 0;
}
