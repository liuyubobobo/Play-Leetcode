/// Source : https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended-ii/
/// Author : liuyubobobo
/// Time   : 2021-02-06

#include <iostream>
#include <vector>

using namespace std;


/// DP + Binary Search
/// Time Complexity: O(nlogn + nklogn)
/// Space Complexity: O(nk)
class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {

        sort(events.begin(), events.end());

        int n = events.size();
        vector<vector<int>> dp(n, vector<int>(k));

        int res = events[n - 1][2];
        dp[n - 1][0] = events[n - 1][2];
        for(int i = n - 2; i >= 0; i --){
            dp[i][0] = max(events[i][2], dp[i + 1][0]);
            res = max(res, dp[i][0]);
        }

        for(int j = 1; j < k; j ++){
            dp[n - 1][j] = events[n - 1][2];
            for(int i = n - 2; i >= 0; i --){
                dp[i][j] = dp[i + 1][j];
                int x = binary_search(events, i + 1, n - 1, events[i][1] + 1);
                if(x < n)
                    dp[i][j] = max(dp[i][j], events[i][2] + dp[x][j - 1]);
                res = max(res, dp[i][j]);
            }
        }
        return res;
    }

private:
    int binary_search(const vector<vector<int>>& events, int L, int R, int t){

        int l = L, r = R + 1;
        while(l < r){
            int mid = (l + r) / 2;
            if(events[mid][0] < t) l = mid + 1;
            else r = mid;
        }
        return l;
    }
};


int main() {

    vector<vector<int>> events1 = {{1, 2, 4}, {2, 3, 10}, {3, 4, 3}};
    cout << Solution().maxValue(events1, 2) << endl;
    // 10

    return 0;
}
