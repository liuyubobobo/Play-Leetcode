/// Created by liuyubobobo on 7/17/17.
/// Leetcode 149. Max Points on a Line
/// https://leetcode.com/problems/max-points-on-a-line/

#include <iostream>
#include <vector>
#include <map>

using namespace std;


/***
 * For each point, iterate all other points
 * Using the hash table(which is unordered_map in this case) to record all the slope
 *
 * In this code, we use map instead of unordered_map,
 * which can use pair as key value natively, and make the performance batter.
 *
 * Time Complexity:  O(n^2)
 * Space Complexity: O(n)
 */


/// Definition for a point.
struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

class Solution {
public:
    int maxPoints(vector<Point>& points) {

        if( points.size() <= 1 )
            return points.size();

        int res = 1;
        for( int i = 0 ; i < points.size() ; i ++ ){

            map<pair<int,int>,int> record;
            int samePoint = 0;
            for( int j = 0 ; j < points.size() ; j ++ ){

                if( points[i].x == points[j].x && points[i].y == points[j].y )
                    samePoint ++;
                else
                    record[slope(points[j], points[i])]++;
            }

            res = max(res, samePoint);    // In case the record is empty and all the points are in the same point.
            for( map<pair<int,int>,int>::iterator iter = record.begin() ; iter != record.end() ; iter ++ )
                res = max( res , iter->second + samePoint );
        }

        return res;
    }

private:
    pair<int,int> slope( const Point &pa, const Point &pb ){

        int dy = pa.y - pb.y;
        int dx = pa.x - pb.x;
        if( dx == 0 )
            return make_pair(1,0);
        if( dy == 0 )
            return make_pair(0,1);

        int g = gcd( abs(dy), abs(dx) );
        dy /= g;
        dx /= g;
        if( dx < 0 ){
            dy = -dy;
            dx = -dx;
        }
        return make_pair( dy , dx );
    }

    int gcd( int a , int b ){

        if( a < b )
            swap( a , b );

        if( a % b == 0 )
            return b;

        return gcd( b , a%b );
    }
};

int main() {

    vector<Point> pvec1;
    pvec1.push_back( Point(1, 1) );
    pvec1.push_back( Point(1, 1) );
    //pvec1.push_back( Point(2, 3) );
    //pvec1.push_back( Point(3, 3) );

    cout<<Solution().maxPoints(pvec1)<<endl;

    return 0;
}