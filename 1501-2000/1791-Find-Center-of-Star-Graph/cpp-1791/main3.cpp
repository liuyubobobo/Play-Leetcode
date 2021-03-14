/// Source : https://leetcode.com/problems/find-center-of-star-graph/
/// Author : liuyubobobo
/// Time   : 2021-03-13

#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;


/// Using Degrees
/// The star's degree must be n - 1
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {

        int n = edges.size() + 1;

        vector<int> degree(n, 0);
        for(const vector<int>& e: edges){
            int a = e[0] - 1, b = e[1] - 1;

            degree[a] ++;
            if(degree[a] == n) return a + 1;

            degree[b] ++;
            if(degree[b] == n) return b + 1;
        }

        assert(false);
        return -1;
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
