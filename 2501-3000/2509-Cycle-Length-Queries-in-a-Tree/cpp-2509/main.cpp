/// Source : https://leetcode.com/problems/cycle-length-queries-in-a-tree/
/// Author : liuyubobobo
/// Time   : 2022-12-18

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/// Math
/// Time Complexity: O(qlogn)
/// Space Complexity: O(logn)
class Solution {
public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {

        int m = queries.size();

        vector<int> res(m);
        for(int qindex = 0; qindex < m; qindex ++){
            int u = queries[qindex][0], v = queries[qindex][1];

            vector<int> upath, vpath;
            while(u) upath.push_back(u), u /= 2;
            while(v) vpath.push_back(v), v /= 2;

            reverse(upath.begin(), upath.end());
            reverse(vpath.begin(), vpath.end());

            int lca_pos = -1;
            for(int i = 0; i < upath.size() && i < vpath.size(); i ++)
                if(upath[i] != vpath[i]){
                    lca_pos = i; break;
                }

            if(lca_pos == -1) lca_pos = min(upath.size(), vpath.size());
            int tres = 0;
            tres += (int)upath.size() - lca_pos;
            tres += (int)vpath.size() - lca_pos;
            tres ++;
            res[qindex] = tres;
        }
        return res;
    }
};


int main() {

    vector<vector<int>> queries1 = {{5, 3}, {4, 7}, {2, 3}};
    Solution().cycleLengthQueries(3, queries1);

    vector<vector<int>> queries2 = {{1, 2}};
    Solution().cycleLengthQueries(2, queries2);

    return 0;
}
