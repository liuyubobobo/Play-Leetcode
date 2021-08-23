/// Source : https://leetcode.com/problems/rectangle-area-ii/
/// Author : liuyubobobo
/// Time   : 2021-08-22

#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;


/// Coordinates Compression
/// Time Complexity: O(n^2)
/// Space Complexity: O(n^2)
class Solution {

private:
    long long MOD = 1e9 + 7;

public:
    int rectangleArea(vector<vector<int>>& rectangles) {

        set<int> xset, yset;
        for(const vector<int>& rec: rectangles){
            int x1 = rec[0], y1 = rec[1], x2 = rec[2], y2 = rec[3];
            xset.insert(x1), xset.insert(x2);
            yset.insert(y1), yset.insert(y2);
        }

        map<int, int> x2c, y2c;
        vector<int> c2x(xset.size()), c2y(yset.size());
        int maxx = 0, maxy = 0;
        for(int x: xset){
            x2c[x] = maxx;
            c2x[maxx] = x;
            maxx ++;
        }
        for(int y: yset){
            y2c[y] = maxy;
            c2y[maxy] = y;
            maxy ++;
        }

        vector<vector<bool>> table(maxx, vector<bool>(maxy, false));
        for(const vector<int>& rec: rectangles){
            int x1 = x2c[rec[0]], y1 = y2c[rec[1]], x2 = x2c[rec[2]], y2 = y2c[rec[3]];
            assert(0 <= x1 && x1 < maxx);
            assert(0 <= y1 && y1 < maxy);
            assert(0 <= x2 && x2 < maxx);
            assert(0 <= y2 && y2 < maxy);
            for(int i = x1; i < x2; i ++)
                for(int j = y1; j < y2; j ++)
                    table[i][j] = true;
        }

        long long res = 0ll;
        for(int i = 0; i + 1 < maxx; i ++)
            for(int j = 0; j + 1 < maxy; j ++)
                if(table[i][j]){
                    int x1 = c2x[i], y1 = c2y[j], x2 = c2x[i + 1], y2 = c2y[j + 1];
                    res += (long long)(x2 - x1) * abs(y2 - y1);
                    res %= MOD;
                }
        return res;
    }
};


int main() {

    vector<vector<int>> rec1 = {
            {0,0,2,2},{1,0,2,3},{1,0,3,1}
    };
    cout << Solution().rectangleArea(rec1) << endl;
    // 6

    vector<vector<int>> rec2 = {
            {0,0,1000000000,1000000000}
    };
    cout << Solution().rectangleArea(rec2) << endl;
    // 49

    vector<vector<int>> rec3 = {
            {25,20,70,27},{68,80,79,100},{37,41,66,76}
    };
    cout << Solution().rectangleArea(rec3) << endl;
    // 1550

    vector<vector<int>> rec4 = {
            {0,0,3,3},{2,0,5,3},{1,1,4,4}
    };
    cout << Solution().rectangleArea(rec4) << endl;
    // 18

    return 0;
}
