/// Source : https://leetcode.com/problems/find-right-interval/
/// Author : liuyubobobo
/// Time   : 2022-05-19

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;


/// Binary Search
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {

        int n = intervals.size();
        vector<pair<pair<int, int>, int>> data(n);
        for(int i = 0; i < n; i ++)
            data[i] = {{intervals[i][0], intervals[i][1]}, i};
        sort(data.begin(), data.end());

        vector<int> res(n, -1);
        for(int i = 0; i < n; i ++){
            int start = data[i].first.first, end = data[i].first.second, index = data[i].second;
            auto iter = lower_bound(data.begin(), data.end(), make_pair(make_pair(end, INT_MIN), INT_MIN));
            if(iter != data.end()) res[index] = iter->second;
        }
        return res;
    }
};


void print_vec(const vector<int>& v){
    for(int e: v) cout << e << ' '; cout << '\n';
}

int main() {

    vector<vector<int>> intervals1 = {{3, 4}, {2, 3}, {1, 2}};
    print_vec(Solution().findRightInterval(intervals1));
    // -1 0 1

    return 0;
}
