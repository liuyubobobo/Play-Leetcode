/// Source : https://leetcode.com/problems/find-maximal-uncovered-ranges/description/
/// Author : liuyubobobo
/// Time   : 2023-04-30

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/// Sorting
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    vector<vector<int>> findMaximalUncoveredRanges(int n, vector<vector<int>>& ranges) {

        sort(ranges.begin(), ranges.end());

        vector<pair<int, int>> segs;
        for(const vector<int>& range: ranges){
            int a = range[0], b = range[1];
            if(segs.empty() || segs.back().second + 1 < a)
                segs.push_back({a, b});
            else segs.back().second = max(segs.back().second, b);
        }

        if(segs.empty()) return vector<vector<int>>(1, {0, n - 1});

        vector<vector<int>> res;
        if(segs[0].first) res.push_back({0, segs[0].first - 1});
        for(int i = 1; i < segs.size(); i++)
            res.push_back({segs[i - 1].second + 1, segs[i].first - 1});
        if(segs.back().second + 1 < n)
            res.push_back({segs.back().second + 1, n - 1});
        return res;
    }
};


int main() {

    return 0;
}
