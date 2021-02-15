/// Source : https://leetcode.com/problems/delivering-boxes-from-storage-to-ports/
/// Author : liuyubobobo
/// Time   : 2021-02-14

#include <iostream>
#include <vector>

using namespace std;


/// Greedy + Memory Search
/// Time Complexity: O(n)?
/// Space Complexity: O(n)
class Solution {

private:
    int maxBoxes, maxWeight;

public:
    int boxDelivering(vector<vector<int>>& boxes, int portsCount, int maxBoxes, int maxWeight) {

        this->maxBoxes = maxBoxes;
        this->maxWeight = maxWeight;

        vector<int> dp(boxes.size(), -1);
        return dfs(boxes, 0, dp);
    }

private:
    int dfs(const vector<vector<int>>& boxes, int index, vector<int>& dp){

        if(index == boxes.size()) return 0;
        if(dp[index] != -1) return dp[index];

        int curboxes = 0, curweight = 0, tres = 0;
        int prevport = -1, previndex = index, prevres = -1, i;
        for(i = index; i < boxes.size(); i ++){

            curboxes += 1;
            curweight += boxes[i][1];

            if(curboxes > maxBoxes || curweight > maxWeight)
                break;

            if(boxes[i][0] != prevport){
                prevport = boxes[i][0];
                previndex = i;
                prevres = tres;
                tres += 1;
            }
        }

        int res = tres + 1 + dfs(boxes,i, dp);
        if(previndex != index)
            res = min(res, prevres + 1 + dfs(boxes, previndex, dp));
        return dp[index] = res;
    }
};


int main() {

    vector<vector<int>> boxes1 = {{1, 1}, {2, 1}, {1, 1}};
    cout << Solution().boxDelivering(boxes1, 2, 3, 3) << endl;
    // 4

    vector<vector<int>> boxes2 = {{1, 2}, {3, 3}, {3, 1}, {3, 1}, {2, 4}};
    cout << Solution().boxDelivering(boxes2, 3, 3, 6) << endl;
    // 6

    vector<vector<int>> boxes3 = {{1, 4}, {1, 2}, {2, 1}, {2, 1}, {3, 2}, {3, 4}};
    cout << Solution().boxDelivering(boxes3, 3, 6, 7) << endl;
    // 6

    vector<vector<int>> boxes4 = {{2, 4}, {2, 5}, {3, 1}, {3, 2}, {3, 7}, {3, 1}, {4, 4}, {1, 3}, {5, 2}};
    cout << Solution().boxDelivering(boxes4, 5, 5, 7) << endl;
    // 14

    return 0;
}
