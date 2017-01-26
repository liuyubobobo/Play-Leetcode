/// Source : https://leetcode.com/problems/max-points-on-a-line/
/// Author : liuyubobobo
/// Time   : 2017-01-26


#include <iostream>
#include <vector>
#include <cassert>
#include <stdexcept>
#include <unordered_map>
#include <algorithm>
#include <util.h>

using namespace std;


/// Problem
/********************************************************************************
 *
 * Given n points on a 2D plane,
 * find the maximum number of points that lie on the same straight line.
 **********************************************************************************/


/// Solution
/***********************************************
 * For each point, iterate all other points
 * Using the hashtable to record all the slope
 *
 * Time Complexity:  O(n^2)
 * Space Complexity: O(n)
 **********************************************/


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

            unordered_map<string,int> record;
            int samePoint = 0;
            record[getPairStr(make_pair(0,0))] = 0;
            for( int j = 0 ; j < points.size() ; j ++ ){

                if( points[i].x == points[j].x && points[i].y == points[j].y )
                    samePoint ++;
                else
                    record[getPairStr(slope(points[j], points[i]))]++;
            }

            for( unordered_map<string,int>::iterator iter = record.begin() ; iter != record.end() ; iter ++ )
                res = max( res , iter->second + samePoint );

            //cout<<"i = "<<i<<" , res = "<<res<<endl;
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
        if( (dy > 0 && dx < 0) || (dy < 0 && dx < 0) ){
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

    string getPairStr( const pair<int,int> p){
        string ret = to_string(p.first) + " " + to_string(p.second);
        //cout<<"getPairStr:"<<ret<<endl;
        return ret;
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