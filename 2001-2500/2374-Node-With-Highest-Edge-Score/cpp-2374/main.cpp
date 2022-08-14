/// Source : https://leetcode.com/problems/node-with-highest-edge-score/
/// Author : liuyubobobo
/// Time   : 2022-08-13

#include <iostream>
#include <vector>

using namespace std;


/// Brute Force
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int edgeScore(vector<int>& edges) {

        int n = edges.size();
        vector<long long> score(n, 0);
        for(int u = 0; u < n; u ++)
            score[edges[u]] += u;

        long long best = score[0];
        int res = 0;
        for(int u = 1; u < n; u ++)
            if(score[u] > best) best = score[u], res = u;
        return res;
    }
};


int main() {

    return 0;
}
