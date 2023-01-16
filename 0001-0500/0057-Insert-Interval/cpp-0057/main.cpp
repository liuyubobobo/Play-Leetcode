/// Source : https://leetcode.com/problems/insert-interval/
/// Author : liuyubobobo
/// Time   : 2023-01-15

#include <iostream>
#include <vector>

using namespace std;


/// Stack
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> res;
        for(const vector<int>& v: intervals){
            if(!res.empty() && is_intersect(res.back(), v)){
                vector<int> x = res.back();
                res.pop_back();
                res.push_back(intersect(x, v));
            }
            else res.push_back(v);
        }
        return res;
    }

private:
    bool is_intersect(const vector<int>& a, const vector<int>& b){
        if(a[0] <= b[0] && b[0] <= a[1]) return true;
        if(b[0] <= a[0] && a[0] <= b[1]) return true;
        return false;
    }

    vector<int> intersect(const vector<int>& a, const vector<int>& b){
        return {min(a[0], b[0]), max(a[1], b[1])};
    }
};


int main() {

    return 0;
}
