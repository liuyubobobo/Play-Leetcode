/// Source : https://leetcode.com/problems/maximum-profit-in-job-scheduling/
/// Author : liuyubobobo
/// Time   : 2019-10-20

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/// Dynamic Programming + Binary Search
/// Forwards
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {

        int n = startTime.size();

        vector<pair<pair<int, int>, int>> vec;
        for(int i = 0; i < n; i ++)
            vec.push_back(make_pair(make_pair(endTime[i], startTime[i]), profit[i]));
        sort(vec.begin(), vec.end());

        vector<int> dp(n, vec[0].second);
        for(int i = 1; i < n; i ++){

            dp[i] = max(dp[i - 1], vec[i].second);

            int preend = vec[i].first.second;
            vector<pair<pair<int, int>, int>>::iterator iter =
                    lower_bound(vec.begin(), vec.begin() + i, make_pair(make_pair(preend, INT_MAX), INT_MAX));
            if(iter == vec.begin() + i) iter--;
            else if(iter->first.first > preend && iter != vec.begin()) iter --;
            if(iter->first.first <= preend)
                dp[i] = max(dp[i], vec[i].second + dp[iter - vec.begin()]);
        }

        return dp[n - 1];
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

    vector<int> startTime4 = {4,2,4,8,2};
    vector<int> endTime4 = {5,5,5,10,8};
    vector<int> profit4 = {1,2,8,10,4};
    cout << Solution().jobScheduling(startTime4, endTime4, profit4) << endl;
    // 18

    return 0;
}