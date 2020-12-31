/// Source : https://leetcode.com/problems/maximum-profit-in-job-scheduling/
/// Author : liuyubobobo
/// Time   : 2019-10-19

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/// Dynamic Programming + Binary Search
/// Backwards
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {

        int n = startTime.size();

        vector<pair<pair<int, int>, int>> vec;
        for(int i = 0; i < n; i ++)
            vec.push_back(make_pair(make_pair(startTime[i], endTime[i]), profit[i]));
        sort(vec.begin(), vec.end());

        vector<int> dp(n, vec.back().second);
        for(int i = n - 2; i >= 0; i --){

            dp[i] = dp[i + 1];

            int nextstart = vec[i].first.second;
            vector<pair<pair<int, int>, int>>::iterator iter =
                    lower_bound(vec.begin() + (i + 1), vec.end(), make_pair(make_pair(nextstart, INT_MIN), INT_MIN));
            if(iter != vec.end())
                dp[i] = max(dp[i], vec[i].second + dp[iter - vec.begin()]);
            else
                dp[i] = max(dp[i], vec[i].second);
        }

        return dp[0];
    }
};


int main() {

    vector<int> startTime1 = {1,2,3,3};
    vector<int> endTime1 = {3,4,5,6};
    vector<int> profit1 = {50,10,40,70};
    cout << Solution().jobScheduling(startTime1, endTime1, profit1) << endl;
    // 120

    vector<int> startTime2 = {1,2,3,4,6};
    vector<int> endTime2 = {3,5,10,6,9};
    vector<int> profit2 = {20,20,100,70,60};
    cout << Solution().jobScheduling(startTime2, endTime2, profit2) << endl;
    // 150

    vector<int> startTime3 = {1,1,1};
    vector<int> endTime3 = {2,3,4};
    vector<int> profit3 = {5,6,4};
    cout << Solution().jobScheduling(startTime3, endTime3, profit3) << endl;
    // 6

    return 0;
}