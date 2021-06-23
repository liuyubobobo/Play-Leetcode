/// Source : https://leetcode.com/problems/max-points-on-a-line/
/// Author : liuyubobobo
/// Time   : 2017-07-17
/// Updated: 2021-06-23

#include <iostream>
#include <vector>
#include <map>

using namespace std;


/// Using Hash Map
/// Using pair directly to record the slopes
/// Time Complexity: O(n^2)
/// Space Complexity: O(n)
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {

        if(points.size() <= 1)
            return points.size();

        int res = 1;
        for( int i = 0 ; i < points.size() ; i ++ ){

            map<pair<int,int>, int> record;
            int samePoint = 0;
            for( int j = 0 ; j < points.size() ; j ++ ){
                if( points[i][0] == points[j][0] && points[i][1] == points[j][1])
                    samePoint ++;
                else
                    record[slope(points[j], points[i])]++;
            }

            res = max(res, samePoint);    // In case the record is empty and all the points are in the same point.
            for(map<pair<int,int>,int>::iterator iter = record.begin() ; iter != record.end() ; iter ++)
                res = max(res, iter->second + samePoint);
        }

        return res;
    }

private:
    pair<int,int> slope(const vector<int>& pa, const vector<int>& pb){

        int dy = pa[1] - pb[1];
        int dx = pa[0] - pb[0];
        if(dx == 0)
            return make_pair(1,0);
        if(dy == 0)
            return make_pair(0,1);

        int g = gcd(abs(dy), abs(dx));
        dy /= g;
        dx /= g;
        if(dx < 0){
            dy = -dy;
            dx = -dx;
        }
        return make_pair(dy, dx);
    }

    int gcd(int a, int b){

        if(a < b)
            swap(a, b);

        if(a % b == 0)
            return b;

        return gcd(b, a%b );
    }
};


int main() {

    vector<vector<int>> pvec1 = {{1, 1}, {1, 1}};
    cout<<Solution().maxPoints(pvec1)<<endl;

    return 0;
}