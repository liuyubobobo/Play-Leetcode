/// Source : https://leetcode.com/problems/k-closest-points-to-origin/
/// Author : liuyubobobo
/// Time   : 2019-01-20

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/// Sorting
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {

        vector<pair<int, pair<int, int>>> v;
        for(const vector<int>& point: points)
            v.push_back(make_pair(point[0] * point[0] + point[1] * point[1], make_pair(point[0], point[1])));
        sort(v.begin(), v.end());

        vector<vector<int>> res;
        for(const pair<int, pair<int, int>>& p: v){
            res.push_back({p.second.first, p.second.second});
            if(res.size() == K) break;
        }
        return res;
    }
};


int main() {

    return 0;
}