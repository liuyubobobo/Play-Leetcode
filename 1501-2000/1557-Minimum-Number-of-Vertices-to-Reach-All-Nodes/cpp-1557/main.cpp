/// Source : https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/description/
/// Author : liuyubobobo
/// Time   : 2023-05-17

#include <iostream>
#include <vector>

using namespace std;


/// Linear Scan
/// Time Complexity: O(m)
/// Space Complexity: O(n)
class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {

        vector<int> d(n, 0);
        for(const vector<int>& edge: edges)
            d[edge[1]]++;

        vector<int> res;
        for(int i = 0; i < n; i++)
            if(d[i] == 0)
                res.push_back(i);
        return res;
    }
};


int main() {

    return 0;
}
