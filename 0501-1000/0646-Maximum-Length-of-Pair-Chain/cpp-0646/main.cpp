/// Source : https://leetcode.com/problems/maximum-length-of-pair-chain/submissions/
/// Author : liuyubobobo
/// Time   : 2022-09-02

#include <iostream>
#include <vector>

using namespace std;


/// DP
/// Time Complexity: O(nlogn + n^2)
/// Space Complexity: O(n)
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {

        int n = pairs.size();
        sort(pairs.begin(), pairs.end());

        vector<int> dp(n, 1);
        for(int i = n - 2; i >= 0; i --){
            for(int j = i + 1; j < n; j ++)
                if(pairs[i][1] < pairs[j][0])
                    dp[i] = max(dp[i], 1 + dp[j]);
        }
        return *max_element(dp.begin(), dp.end());
    }
};


int main() {

    return 0;
}
