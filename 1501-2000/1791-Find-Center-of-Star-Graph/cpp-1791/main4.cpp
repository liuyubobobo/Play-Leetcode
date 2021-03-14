/// Source : https://leetcode.com/problems/find-center-of-star-graph/
/// Author : liuyubobobo
/// Time   : 2021-03-13

#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;


/// The star must occurs in every edge
/// Time Complexity: O(1)
/// Space Complexity: O(1)
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {

        if(edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1]) return edges[0][0];
        return edges[0][1];
    }
};


int main() {

    vector<vector<int>> edges1 = {
            {1,2},{2,3},{4,2}
    };
    cout << Solution().findCenter(edges1) << endl;
    // 2

    vector<vector<int>> edges2 = {
            {1,2},{5,1},{1,3},{1,4}
    };
    cout << Solution().findCenter(edges2) << endl;
    // 1

    return 0;
}
