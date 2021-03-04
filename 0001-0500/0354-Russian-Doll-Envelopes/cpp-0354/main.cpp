/// Source : https://leetcode.com/problems/russian-doll-envelopes/
/// Author : liuyubobobo
/// Time   : 2021-03-03

#include <iostream>
#include <vector>

using namespace std;


/// LIS
/// Time Complexity: O(n^2)
/// Space Complexity: O(n)
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {

        if(envelopes.empty()) return 0;

        sort(envelopes.begin(), envelopes.end());

        vector<int> dp(envelopes.size(), 1);
        for(int i = 1; i < envelopes.size(); i ++){
            dp[i] = 1;
            for(int j = i - 1; j >= 0; j --)
                if(envelopes[i][0] > envelopes[j][0] && envelopes[i][1] > envelopes[j][1])
                    dp[i] = max(dp[i], 1 + dp[j]);
        }
        return *max_element(dp.begin(), dp.end());
    }
};


int main() {

    vector<vector<int>> envelopes1 = {
            {5,4},{6,4},{6,7},{2,3}
    };
    cout << Solution().maxEnvelopes(envelopes1) << endl;
    // 3

    vector<vector<int>> envelopes2 = {
            {1,3},{3,5},{6,7},{6,8},{8,4},{9,5}
    };
    cout << Solution().maxEnvelopes(envelopes2) << endl;
    // 3

    return 0;
}
