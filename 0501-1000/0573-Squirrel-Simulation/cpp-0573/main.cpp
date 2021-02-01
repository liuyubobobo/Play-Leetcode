/// Source : https://leetcode.com/problems/squirrel-simulation/
/// Author : liuyubobobo
/// Time   : 2021-02-01

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


/// Brute Force
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int minDistance(int height, int width, vector<int>& tree, vector<int>& squirrel, vector<vector<int>>& nuts) {

        vector<int> treeToNuts, squToNuts;
        for(const vector<int>& nut: nuts) {
            treeToNuts.push_back(abs(nut[0] - tree[0]) + abs(nut[1] - tree[1]));
            squToNuts.push_back(abs(nut[0] - squirrel[0]) + abs(nut[1] - squirrel[1]));
        }

        int total = accumulate(treeToNuts.begin(), treeToNuts.end(), 0);
        int res = INT_MAX;
        for(int i = 0; i < nuts.size(); i ++){
            res = min(res, squToNuts[i] + treeToNuts[i] + total * 2 - 2 * treeToNuts[i]);
        }
        return res;
    }
};


int main() {

    return 0;
}
