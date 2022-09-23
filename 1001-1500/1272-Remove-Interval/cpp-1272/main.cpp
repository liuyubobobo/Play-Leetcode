/// Source : https://leetcode.com/problems/remove-interval/
/// Author : liuyubobobo
/// Time   : 2022-09-23

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/// Ad-Hoc
/// Time Complexity: O(nlogn)
/// Space Complexity: O(1)
class Solution {
public:
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {

        sort(intervals.begin(), intervals.end());

        int x = toBeRemoved[0], y = toBeRemoved[1] - 1;

        vector<vector<int>> res;
        for(const vector<int>& v: intervals){
            int a = v[0], b = v[1] - 1;
            if(x < a){
                if(y < a) res.push_back({a, b + 1});
                else if(y <= b - 1) res.push_back({y + 1, b + 1});
                else continue;
            }
            else if(x == a){
                if(y <= b - 1) res.push_back({y + 1, b + 1});
                else continue;
            }
            else if(x <= b){
                if(y <= b - 1) res.push_back({a, x}), res.push_back({y + 1, b + 1});
                else res.push_back({a, x});
            }
            else res.push_back({a, b + 1});
        }
        return res;
    }
};


int main() {

    return 0;
}
