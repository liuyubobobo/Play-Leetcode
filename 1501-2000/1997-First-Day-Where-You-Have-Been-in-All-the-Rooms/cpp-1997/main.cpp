/// Source : https://leetcode.com/problems/first-day-where-you-have-been-in-all-the-rooms/
/// Author : liuyubobobo
/// Time   : 2021-09-04

#include <iostream>
#include <vector>

using namespace std;


/// DP
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {

private:
    const long long MOD = 1e9 + 7;

public:
    int firstDayBeenInAllRooms(vector<int>& nextVisit) {

        int n = nextVisit.size(), res = 0;
        vector<long long> dp(n, 0);
        dp[1] = 2;

        for(int i = 2; i < n; i ++)
            if(nextVisit[i - 1] == i - 1)
                dp[i] = (dp[i - 1] + 2) % MOD;
            else
                dp[i] = (dp[i - 1] + (dp[i - 1] - dp[nextVisit[i - 1]]) + 2 + MOD) % MOD;

        return dp.back();
    }
};


int main() {

    vector<int> next1 = {0, 0};
    cout << Solution().firstDayBeenInAllRooms(next1) << endl;
    // 2

    vector<int> next2 = {0, 0, 2};
    cout << Solution().firstDayBeenInAllRooms(next2) << endl;
    // 6

    vector<int> next3 = {0, 1, 2, 0};
    cout << Solution().firstDayBeenInAllRooms(next3) << endl;
    // 6

    vector<int> next4 = {0,0,0,0,0,0,0,0,0,9,1,8};
    cout << Solution().firstDayBeenInAllRooms(next4) << endl;
    // 2048

    return 0;
}
