/// Source : https://leetcode.com/problems/make-array-strictly-increasing/
/// Author : liuyubobobo
/// Time   : 2019-09-07

#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;


/// Memory Search
/// Time Complexity: O(n*m*logm)
/// Space Complexity: O(n*m)
class Solution {

private:
    int MAX;

public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {

        set<int> set;
        for(int e: arr2) set.insert(e);

        arr2 = vector<int>(set.begin(), set.end());
        MAX = arr2.size() + 1;

        vector<vector<int>> dp(arr1.size(), vector<int>(arr2.size() + 1, -1));
        int res = go(arr1, arr2, 0, 0, dp);
        for(int j = 0; j < arr2.size(); j ++)
            res = min(res, (arr1[0] != arr2[0]) + go(arr1, arr2, 0, j + 1, dp));
        return res >= MAX ? -1 : res;
    }

private:
    int go(const vector<int>& arr1, const vector<int>& arr2, int i, int j,
           vector<vector<int>>& dp){

        if(i + 1 == arr1.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int last = j == 0 ? arr1[i] : arr2[j - 1];
        int res = MAX;
        if(arr1[i + 1] > last)
            res = min(res, go(arr1, arr2, i + 1, 0, dp));

        vector<int>::const_iterator iter = upper_bound(arr2.begin(), arr2.end(), last);
        if(iter != arr2.end()){
            int jj = iter - arr2.begin();
            res = min(res, 1 + go(arr1, arr2, i + 1, jj + 1, dp));
        }
        return dp[i][j] = res;
    }
};


int main() {

    vector<int> a1 = {1, 5, 3, 6, 7}, b1 = {1, 3, 2, 4};
    cout << Solution().makeArrayIncreasing(a1, b1) << endl;
    // 1

    vector<int> a2 = {1, 5, 3, 6, 7}, b2 = {4, 3, 1};
    cout << Solution().makeArrayIncreasing(a2, b2) << endl;
    // 2

    vector<int> a3 = {1, 5, 3, 6, 7}, b3 = {1, 6, 3, 3};
    cout << Solution().makeArrayIncreasing(a3, b3) << endl;
    // -1
    return 0;
}