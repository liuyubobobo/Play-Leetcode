/// Source : https://leetcode.com/problems/closest-dessert-cost/
/// Author : liuyubobobo
/// Time   : 2021-03-03

#include <iostream>
#include <vector>

using namespace std;


/// Backtracking
/// Time Complexity: O(n * 3^m)
/// Space Complexity: O(m)
class Solution {

private:
    int best;

public:
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {

        best = -1e9;
        for(int base: baseCosts){
            dfs(toppingCosts, 0, base, target);
        }
        return best;
    }

private:
    void dfs(const vector<int>& toppings, int index, int cur, int target){

        if(index == toppings.size()){
            if(abs(cur - target) < abs(best - target))
                best = cur;
            else if(abs(cur - target) == abs(best - target) && cur < best)
                best = cur;
            return;
        }

        for(int i = 0; i <= 2; i ++)
            dfs(toppings, index + 1, cur + i * toppings[index], target);
        return;
    }
};


int main() {

    vector<int> baseCosts1 = {1, 7}, toppingCosts1 = {3, 4};
    cout << Solution().closestCost(baseCosts1, toppingCosts1, 10) << endl;
    // 10

    vector<int> baseCosts2 = {2, 3}, toppingCosts2 = {4, 5, 100};
    cout << Solution().closestCost(baseCosts2, toppingCosts2, 18) << endl;
    // 17

    vector<int> baseCosts3 = {3, 10}, toppingCosts3 = {2, 5};
    cout << Solution().closestCost(baseCosts3, toppingCosts3, 9) << endl;
    // 8

    vector<int> baseCosts4 = {10}, toppingCosts4 = {1};
    cout << Solution().closestCost(baseCosts4, toppingCosts4, 1) << endl;
    // 10

    vector<int> baseCosts5 = {5, 9}, toppingCosts5 = {10, 1};
    cout << Solution().closestCost(baseCosts5, toppingCosts5, 7) << endl;
    // 7

    return 0;
}
