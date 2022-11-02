/// Source : https://leetcode.com/problems/coordinate-with-maximum-network-quality/
/// Author : liuyubobobo
/// Time   : 2020-10-18
/// Updated: 2022-11-01

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O((maxx - minx) * (maxy - miny) * |towers|)
/// Space Complexity: O(1)
class Solution {
public:
    vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {

        int minx = INT_MAX, miny = INT_MAX, maxx = INT_MIN, maxy = INT_MIN;
        for(const vector<int>& tower: towers){
            minx = min(minx, tower[0] - tower[2]);
            miny = min(miny, tower[1] - tower[2]);
            maxx = max(maxx, tower[0] + tower[2]);
            maxy = max(maxy, tower[1] + tower[2]);
        }

        vector<int> res;
        int maxq = 0;
        for(int x = minx; x <= maxx; x ++)
            for(int y = miny; y <= maxy; y ++){
                int curq = getq(towers, x, y, radius);
                if(curq > maxq) res = {x, y}, maxq = curq;
        }
        return maxq == 0 ? vector<int>(2, 0) : res;
    }

private:
    int getq(const vector<vector<int>>& towers, int x, int y, int r){

        int res = 0;
        for(const vector<int>& e: towers){
            int d2 = (e[0] - x) * (e[0] - x) + (e[1] - y) * (e[1] - y);
            if(d2 <= r * r)
                res += (int)(e[2] / (1 + sqrt(d2)));
        }
        return res;
    }
};


int main() {


    return 0;
}
