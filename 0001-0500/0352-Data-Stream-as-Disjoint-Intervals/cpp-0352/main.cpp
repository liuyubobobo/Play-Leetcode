/// Source : https://leetcode.com/problems/data-stream-as-disjoint-intervals/
/// Author : liuyubobobo
/// Time   : 2021-10-08

#include <iostream>
#include <vector>
#include <map>

using namespace std;


/// Using Map to record Segments
/// Time Complexity: init : O(1)
///                  addNum: O(logn)
///                  get_interval: O(m) where m is the segments number
/// Space Complexity: O(m)
class SummaryRanges {

private:
    map<int, int> left; // l, r
    map<int, int> right; // r, l;

public:
    SummaryRanges() {}

    void addNum(int val) {

        if(!left.empty()) {
            map<int, int>::iterator iter = left.upper_bound(val);
            if (iter != left.begin()) iter--;
            if (iter->first <= val && val <= iter->second) return;
        }

        pair<int, int> interval = {val, val};
        if(right.count(val - 1)){
            int r = val - 1, l = right[r];
            right.erase(r);
            left.erase(l);
            interval.first = l;
        }
        if(left.count(val + 1)){
            int l = val + 1, r = left[l];
            left.erase(l);
            right.erase(r);
            interval.second = r;
        }

        left[interval.first] = interval.second;
        right[interval.second] = interval.first;
    }

    vector<vector<int>> getIntervals() {

        vector<vector<int>> res;
        for(const pair<int, int>& p: left)
            res.push_back({p.first, p.second});
        return res;
    }
};


int main() {

    return 0;
}
