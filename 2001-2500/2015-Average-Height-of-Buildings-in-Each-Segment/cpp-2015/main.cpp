/// Source : https://leetcode.com/problems/average-height-of-buildings-in-each-segment/
/// Author : liuyubobobo
/// Time   : 2021-09-24

#include <iostream>
#include <vector>

using namespace std;


/// Sweep Line
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    vector<vector<int>> averageHeightOfBuildings(vector<vector<int>>& buildings) {

        vector<pair<int, int>> seg;
        for(const vector<int>& b: buildings)
            seg.push_back({b[0], b[2]}),
            seg.push_back({b[1], -b[2]});
        sort(seg.begin(), seg.end());

        vector<vector<int>> res;
        int start = seg[0].first, cur_h = seg[0].second, cur_cnt = 1;
        for(int i = 1; i < seg.size(); i ++){
            if(cur_cnt && seg[i].first != start){
                vector<int> x = {start, seg[i].first, cur_h / cur_cnt};
                if(!res.empty() && x[2] != res.back()[2] && x[0] == res.back()[1])
                    res.back()[1] = x[1];
                else
                    res.push_back(x);
            }

            start = seg[i].first;
            cur_h += seg[i].second;
            cur_cnt += sign(seg[i].second);
        }
        return res;
    }

private:
    int sign(int x){
        if(x > 0) return 1;
        return x < 0 ? -1 : 0;
    }
};


int main() {

    return 0;
}
