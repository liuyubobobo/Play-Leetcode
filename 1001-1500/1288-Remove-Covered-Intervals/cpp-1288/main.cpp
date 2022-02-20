/// Source : https://leetcode.com/problems/remove-covered-intervals/
/// Author : liuyubobobo
/// Time   : 2022-02-19

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O(nlogn + n^2)
/// Space Complexity: O(n)
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& va, const vector<int>& vb){
            if(va[1] - va[0] != vb[1] - vb[0])
                return va[1] - va[0] > vb[1] - vb[0];
            return va[0] < vb[0];
        });

        vector<vector<int>> res;
        for(const vector<int>& v: intervals)
            if(!contains(res, v)) res.push_back(v);
        return res.size();
    }

private:
    bool contains(const vector<vector<int>>& res, const vector<int>& a){

        for(const vector<int>& v: res)
            if(v[0] <= a[0] && a[1] <= v[1]) return true;
        return false;
    }
};

int main() {

    return 0;
}
