/// Source : https://leetcode.com/problems/minimum-number-of-refueling-stops/description/
/// Author : liuyubobobo
/// Time   : 2018-08-05

#include <iostream>
#include <vector>

using namespace std;


/// Dynamic Programming
/// Time Complexity: O(n^3)
/// Space Complexity: O(n^2)
class Solution {

public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {

        if(startFuel >= target)
            return 0;

        int n = stations.size();
        vector<vector<int>> dp(n + 1, vector<int>(n, 0));
        for(int i = n - 1; i >= 0; i --)
            if(startFuel >= stations[i][0]){
                dp[1][i] = startFuel + stations[i][1];
                if(dp[1][i] >= target)
                    return 1;
            }

        for(int k = 2; k <= n; k ++){
            for(int last = k - 2; last < n; last ++)
                for(int cur = last + 1; cur < n ; cur ++)
                    if(dp[k-1][last] >= stations[cur][0]){
                        dp[k][cur] = max(dp[k][cur], dp[k-1][last] + stations[cur][1]);
                        if(dp[k][cur] >= target)
                            return k;
                    }
                    else
                        break;
        }
        return -1;
    }
};


int main() {

    int target1 = 1, startFuel1 = 1;
    vector<vector<int>> stations1;
    cout << Solution().minRefuelStops(target1, startFuel1, stations1) << endl;
    // 0

    int target2 = 100, startFuel2 = 1;
    vector<vector<int>> stations2 = {{10, 100}};
    cout << Solution().minRefuelStops(target2, startFuel2, stations2) << endl;
    // -1

    int target3 = 100, startFuel3 = 10;
    vector<vector<int>> stations3 = {{10, 60}, {20, 30}, {30, 30}, {60, 40}};
    cout << Solution().minRefuelStops(target3, startFuel3, stations3) << endl;
    // 2

    int target4 = 1000, startFuel4 = 83;
    vector<vector<int>> stations4 = {{25, 27}, {36, 187}, {140, 186}, {378, 6}, {492, 202},
                                     {517, 89}, {579, 234}, {673, 86}, {808, 53}, {954, 49}};
    cout << Solution().minRefuelStops(target4, startFuel4, stations4) << endl;
    // -1

    return 0;
}