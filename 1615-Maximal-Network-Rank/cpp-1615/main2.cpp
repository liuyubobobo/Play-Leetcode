/// Source : https://leetcode.com/problems/maximal-network-rank/
/// Author : liuyubobobo
/// Time   : 2020-10-14

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


/// Greedy
/// See here for reference: https://leetcode-cn.com/problems/maximal-network-rank/solution/onm-mei-ju-fa-by-zerotrac2/
/// Time Complexity: O(V + E)
/// Space Complexity: O(V)
class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {

        vector<unordered_set<int>> g(n);
        vector<int> degrees(n);
        for(const vector<int>& e: roads)
            degrees[e[0]] ++, degrees[e[1]] ++,
            g[e[0]].insert(e[1]), g[e[1]].insert(e[0]);

        int first_max = max(degrees[0], degrees[1]),
            second_max = degrees[0] == degrees[1] ? 0 : min(degrees[0], degrees[1]),
            max_cnt = (degrees[0] == degrees[1] ? 2 : 1);
        for(int i = 2; i < n; i ++)
            if(degrees[i] > first_max)
                second_max = first_max, first_max = degrees[i], max_cnt = 1;
            else if(degrees[i] == first_max) max_cnt ++;
            else if(degrees[i] > second_max)
                second_max = degrees[i];

        if(max_cnt > 1){
            int c = max_cnt * (max_cnt - 1) / 2;
            if(c > roads.size())
                return 2 * first_max;

            for(const vector<int>& e: roads)
                if(degrees[e[0]] == first_max && degrees[e[1]] == first_max)
                    c --;

            if(c) return 2 * first_max;
            return 2 * first_max - 1;
        }

        int city = -1;
        for(int i = 0; i < n; i ++)
            if(degrees[i] == first_max){
                city = i; break;
            }

        for(int i = 0; i < n; i ++)
            if(degrees[i] == second_max && !g[city].count(i))
                return first_max + second_max;
        return first_max + second_max - 1;
    }
};


int main() {

    vector<vector<int>> roads1 = {{0,1},{0,3},{1,2},{1,3}};
    cout << Solution().maximalNetworkRank(4, roads1) << endl;
    // 4

    vector<vector<int>> roads2 = {{0,1},{0,3},{1,2},{1,3},{2,3},{2,4}};
    cout << Solution().maximalNetworkRank(5, roads2) << endl;
    // 5

    vector<vector<int>> roads3 = {{0,1},{1,2},{2,3},{2,4},{5,6},{5,7}};
    cout << Solution().maximalNetworkRank(8, roads3) << endl;
    // 5

    vector<vector<int>> roads4 = {{0,1}};
    cout << Solution().maximalNetworkRank(2, roads4) << endl;
    // 1

    return 0;
}
