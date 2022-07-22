/// Source : https://leetcode.com/problems/finding-the-number-of-visible-mountains/
/// Author : liuyubobobo
/// Time   : 2022-07-22

#include <iostream>
#include <vector>
#include <climits>

using namespace std;


/// Points Transformation
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    int visibleMountains(vector<vector<int>>& peaks) {

        int n = peaks.size();

        vector<pair<int, int>> points(n);
        for(int i = 0; i < n; i ++){
            int x = peaks[i][0], y = peaks[i][1];
            points[i] = {x + y, y - x};
        }

        sort(points.begin(), points.end(), greater<pair<int, int>>());

        int res = 0, ylimit = INT_MIN;
        for(int i = 0; i < n; i ++){
            int x = points[i].first, y = points[i].second;

            if(i + 1 < n && points[i + 1] == points[i]){
                ylimit = max(ylimit, y);
                continue;
            }

            if(i && x == points[i - 1].first) continue;

            if(y > ylimit) res ++;
            ylimit = max(ylimit, y);
        }
        return res;
    }
};


int main() {

    vector<vector<int>> peaks1 = {{2, 2}, {6, 3}, {5, 4}};
    cout << Solution().visibleMountains(peaks1) << '\n';
    // 2

    vector<vector<int>> peaks2 = {{1, 3}, {1, 3}};
    cout << Solution().visibleMountains(peaks2) << '\n';
    // 0

    return 0;
}
