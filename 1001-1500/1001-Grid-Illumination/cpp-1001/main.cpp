/// Source : https://leetcode.com/problems/grid-illumination/
/// Author : liuyubobobo
/// Time   : 2019-02-23

#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;


/// Using HashSet
/// Time Complexity: O(n + q)
/// Space Complexity : O(n)
class Solution {
public:
    vector<int> gridIllumination(int N, vector<vector<int>>& lamps, vector<vector<int>>& queries) {

        set<pair<int, int>> lamp_set;
        for(const vector<int>& lamp: lamps){
            int x = lamp[0], y = lamp[1];
            lamp_set.insert(make_pair(x, y));
        }

        unordered_map<int, int> row, col, dia1, dia2;
        for(const pair<int, int>& lamp: lamp_set){
            int x = lamp.first, y = lamp.second;
            row[x] ++;
            col[y] ++;
            dia1[x - y] ++;
            dia2[x + y] ++;
        }

        vector<int> res;
        for(const vector<int>& q: queries){
            int x = q[0], y = q[1];
            if(row[x] || col[y] || dia1[x - y] || dia2[x + y])
                res.push_back(1);
            else res.push_back(0);

            for(int i = -1; i <= 1; i ++)
                for(int j = -1; j <= 1; j ++){
                    int xx = x + i, yy = y + j;
                    pair<int, int> pp = make_pair(xx, yy);
                    if(lamp_set.count(pp)){
                        lamp_set.erase(pp);
                        row[xx] --;
                        col[yy] --;
                        dia1[xx - yy] --;
                        dia2[xx + yy] --;
                    }
                }
        }
        return res;
    }
};


void print_vec(const vector<int>& vec){
    for(int e: vec) cout << e << " ";
    cout << endl;
}

int main() {

    vector<vector<int>> lamps1 = {{0, 0}, {4, 4}};
    vector<vector<int>> queries1 = {{1, 1}, {1, 0}};
    print_vec(Solution().gridIllumination(5, lamps1, queries1));

    vector<vector<int>> lamps2 = {{2,5},{4,2},{0,3},{0,5},{1,4},{4,2},{3,3},{1,0}};
    vector<vector<int>> queries2 = {{4,3},{3,1},{5,3},{0,5},{4,4},{3,3}};
    print_vec(Solution().gridIllumination(6, lamps2, queries2));
    // 1 0 1 1 0 1

    return 0;
}