/// Source : https://leetcode.com/problems/queries-on-number-of-points-inside-a-circle/
/// Author : liuyubobobo
/// Time   : 2021-04-17

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O(|p| * |q|)
class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {

        vector<int> res;
        for(const vector<int>& q: queries)
            res.push_back(query(points, q[0], q[1], q[2]));
        return res;
    }

private:
    int query(const vector<vector<int>>& points, int x, int y, int r){

        int res = 0;
        for(const vector<int>& p: points)
            res += (x - p[0]) * (x - p[0]) + (y - p[1]) * (y - p[1]) <= r * r;
        return res;
    }
};


int main() {

    return 0;
}
