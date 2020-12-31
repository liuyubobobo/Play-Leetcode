/// Source : https://leetcode.com/problems/form-largest-integer-with-digits-that-add-up-to-target/
/// Author : liuyubobobo
/// Time   : 2020-05-16

#include <iostream>
#include <vector>

using namespace std;


/// Memory Search
/// Time Complexity: O(target)
/// Space Complexity: O(target * |s|)
class Solution {
public:
    string largestNumber(vector<int>& cost, int target) {

        vector<string> dp(target + 1);
        vector<bool> visited(target + 1);
        string res =  dfs(cost, target, dp, visited);
        return res.size() ? res : "0";
    }

private:
    string dfs(const vector<int>& cost, int target,
               vector<string>& dp, vector<bool>& visited){

        if(visited[target]) return dp[target];

        string res = "";
        for(int i = 8; i >= 0; i --)
            if(target > cost[i]){
                string tres = dfs(cost, target - cost[i], dp, visited);
                if(tres != "" && tres.size() + 1 > res.size())
                    res = string(1, '0' + (1 + i)) + tres;
            }
            else if(target == cost[i] && res.size() == 0)
                res += ('0' + (1 + i));

        visited[target] = true;
        return dp[target] = res;
    }
};


int main() {

    vector<int> cost1 = {4,3,2,5,6,7,2,5,5};
    cout << Solution().largestNumber(cost1, 9) << endl;
    // 7772

    vector<int> cost2 = {7,6,5,5,5,6,8,7,8};
    cout << Solution().largestNumber(cost2, 12) << endl;
    // 85

    vector<int> cost3 = {210,77,91,105,378,333,316,323,353};
    cout << Solution().largestNumber(cost3, 1217) << endl;
    // 9944443

    return 0;
}
