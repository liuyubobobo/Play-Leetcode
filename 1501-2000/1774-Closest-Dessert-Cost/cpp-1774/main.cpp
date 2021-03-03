/// Source : https://leetcode.com/problems/closest-dessert-cost/
/// Author : liuyubobobo
/// Time   : 2021-02-27

#include <iostream>
#include <vector>

using namespace std;


/// DP + Binary Search
/// Time Complexity: O((1 << 2m)log(1 << 2m) + nlog(1 << 2m))
/// Space Complexity: O(1 << 2m)
class Solution {
public:
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {

        vector<int> v = toppingCosts;
        for(int e: toppingCosts)
            v.push_back(e);

        int m = v.size();
        vector<int> options(1 << m, 0);
        for(int state = 1; state < (1 << m); state ++){
            int pos = __builtin_ffs(state) - 1;
            options[state] = options[state - (1 << pos)] + v[pos];
        }
        sort(options.begin(), options.end());

        int best = -1e9;
        for(int base: baseCosts){

            int t = target - base;
            vector<int>::iterator iter = lower_bound(options.begin(), options.end(), t);
            if(iter != options.end()){
                int price = base + *iter;
                if(abs(price - target) < abs(best - target))
                    best = price;
                else if(abs(price - target) ==abs(best - target) && price < best)
                    best = price;
            }

            if(iter != options.begin()){
                iter --;
                int price = base + *iter;
                if(abs(price - target) < abs(best - target))
                    best = price;
                else if(abs(price - target) ==abs(best - target) && price < best)
                    best = price;
            }
        }
        return best;
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
