/// Source : https://leetcode.com/problems/maximum-building-height/
/// Author : liuyubobobo
/// Time   : 2021-04-24

#include <iostream>
#include <vector>
#include <stack>

using namespace std;


/// Two Pass
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {

        restrictions.push_back({1, 0});
        sort(restrictions.begin(), restrictions.end());
        if(restrictions.back()[0] != n)
            restrictions.push_back({n, (int)2e9});

        vector<pair<int, int>> v = {{1, 0}};
        for(int i = 1; i < restrictions.size(); i ++){
            int p = restrictions[i][0], h = restrictions[i][1];
            if(h >= v.back().second)
                v.push_back({p, h});
            else{
                pair<int, int> pre = {-1, -1};
                while(v.back().second > h && v.back().second - h > p - v.back().first)
                    pre = v.back(), v.pop_back();

                if(pre.first != -1)
                    v.push_back({pre.first, h + (p - pre.first)});
                v.push_back({p, h});
            }
        }

        int res = 0, pre = 0;
        for(int i = 1; i < v.size(); i ++){
            int p1 = v[i - 1].first, h1 = pre;
            int p2 = v[i].first, h2 = v[i].second;

            if(h2 >= h1 && h2 - h1 >= p2 - p1){
                res = max(res, h1 + p2 - p1);
                pre = h1 + (p2 - p1);
            }
            else if(h2 < h1 && h1 - h2 >= p2 - p1)
                pre = h1 - (p2 - p1);
            else{
                int x = ((long long)h2 - h1 + p1 + p2) / 2ll;
                res = max(res, h1 + x - p1);
                int maxh = h1 + x - p1;
                pre = max(maxh - (p2 - x), h2);
            }
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
