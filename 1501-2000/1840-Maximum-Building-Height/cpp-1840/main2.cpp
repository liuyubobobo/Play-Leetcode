/// Source : https://leetcode.com/problems/maximum-building-height/
/// Author : liuyubobobo
/// Time   : 2021-04-26

#include <iostream>
#include <vector>
#include <stack>

using namespace std;


/// Three Pass
/// Time Complexity: O(nlogn)
/// Space Complexity: O(1)
class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& r) {

        r.push_back({1, 0});
        sort(r.begin(), r.end());
        if(r.back()[0] != n)
            r.push_back({n, (int)2e9});

        for(int i = 1; i < r.size(); i ++)
            r[i][1] = min(r[i][1], r[i - 1][1] + r[i][0] - r[i - 1][0]);

        for(int i = (int)r.size() - 2; i >= 0; i --)
            r[i][1] = min(r[i][1], r[i + 1][1] + r[i + 1][0] - r[i][0]);

        int res = 0;
        for(int i = 1; i < r.size(); i ++){
            int p1 = r[i - 1][0], h1 = r[i - 1][1];
            int p2 = r[i][0], h2 = r[i][1];

            int x = ((long long)h2 - h1 + p1 + p2) / 2ll;
            res = max(res, h1 + x - p1);
        }
        return res;
    }
};


int main() {

    vector<vector<int>> r1 = {{2, 1}, {4, 1}};
    cout << Solution().maxBuilding(5, r1) << endl;
    // 2

    vector<vector<int>> r2 = {};
    cout << Solution().maxBuilding(6, r2) << endl;
    // 5

    vector<vector<int>> r3 = {{5, 3}, {2, 5}, {7, 4}, {10, 3}};
    cout << Solution().maxBuilding(10, r3) << endl;
    // 5

    vector<vector<int>> r4 = {{6, 2}, {5, 1}, {2, 4}, {3, 0}, {9, 5}, {7, 0}, {4, 2}, {10, 3}, {8, 0}};
    cout << Solution().maxBuilding(10, r4) << endl;
    // 2

    vector<vector<int>> r5 = {{2, 4}, {3, 3}};
    cout << Solution().maxBuilding(3, r5) << endl;
    // 2

    return 0;
}
