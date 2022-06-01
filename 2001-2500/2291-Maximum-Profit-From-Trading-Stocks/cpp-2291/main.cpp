/// Source : https://leetcode.com/problems/maximum-profit-from-trading-stocks/
/// Author : liuyubobobo
/// Time   : 2022-05-31

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


/// DP
/// Time Complexity: O(n * budget)
/// Space Complexity: O(n + budget)
class Solution {
public:
    int maximumProfit(vector<int>& present, vector<int>& future, int budget) {

        int n = present.size();

        vector<int> values, weight;
        for(int i = 0; i < n; i ++)
            if(future[i] > present[i] && present[i] <= budget){
                values.push_back(future[i] - present[i]);
                weight.push_back(present[i]);
            }

        vector<int> dp(budget + 1, 0);
        for(int i = 0; i < values.size(); i ++){
            vector<int> tdp = dp;
            for(int j = budget; j >= weight[i]; j --)
                tdp[j] = max(tdp[j], tdp[j - weight[i]] + values[i]);
            dp = tdp;
        }
        return dp.back();
    }
};


int main() {

    vector<int> present = {2,2,5}, future = {3,4,10};
    cout << Solution().maximumProfit(present, future, 6) << '\n';
    // 5

    return 0;
}
