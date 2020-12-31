/// Source : https://leetcode.com/problems/best-team-with-no-conflicts/
/// Author : liuyubobobo
/// Time   : 2020-10-17

#include <iostream>
#include <vector>

using namespace std;


/// LIS
/// Time Complexity: O(n^2)
/// Space Complexity: O(n)
class Solution {

public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {

        int n = scores.size();
        vector<pair<int, int>> v(n);
        for(int i = 0; i < n; i ++) v[i].first = ages[i], v[i].second = scores[i];
        sort(v.begin(), v.end());

        vector<int> dp(n, 0);
        dp[0] = v[0].second;
        for(int i = 1; i < n; i ++){
            dp[i] = v[i].second;
            for(int j = i - 1; j >= 0; j --)
                if(v[i].second >= v[j].second)
                    dp[i] = max(dp[i], v[i].second + dp[j]);
        }
        return *max_element(dp.begin(), dp.end());
    }
};


int main() {

    vector<int> scores1 = {1, 3, 5, 10, 15}, ages1 = {1, 2, 3, 4, 5};
    cout << Solution().bestTeamScore(scores1, ages1) << endl;
    // 34

    vector<int> scores2 = {4,5,6,5}, ages2 = {2,1,2,1};
    cout << Solution().bestTeamScore(scores2, ages2) << endl;
    // 16

    vector<int> scores3 = {1,2,3,5}, ages3 = {8,9,10,1};
    cout << Solution().bestTeamScore(scores3, ages3) << endl;
    // 6

    return 0;
}
