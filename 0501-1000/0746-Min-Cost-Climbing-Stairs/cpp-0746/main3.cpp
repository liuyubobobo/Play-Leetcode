/// Source : https://leetcode.com/problems/min-cost-climbing-stairs/
/// Author : liuyubobobo
/// Time   : 2018-10-29

#include <iostream>
#include <vector>

using namespace std;


/// Dynamic Programming
/// Space Complexity Optimized
///
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {

        cost.push_back(0);
        int a = cost[0];
        int b = cost[1];
        for(int i = 2 ; i < cost.size() ; i ++){
            int c = min(a, b) + cost[i];
            a = b;
            b = c;
        }
        return b;
    }
};


int main() {

    vector<int> vec1 = {10, 15, 20};
    cout << Solution().minCostClimbingStairs(vec1) << endl;

    vector<int> vec2 = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    cout << Solution().minCostClimbingStairs(vec2) << endl;

    return 0;
}