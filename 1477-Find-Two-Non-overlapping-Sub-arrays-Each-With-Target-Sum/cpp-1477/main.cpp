/// Source : https://leetcode.com/problems/maximum-students-taking-exam/
/// Author : liuyubobobo
/// Time   : 2020-06-13

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/// Sliding Windows to get intervals and postsum to get the final result
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {

public:
    int minSumOfLengths(vector<int>& arr, int target) {

        vector<pair<int, int>> sub = get_subarrays(arr, target);
//        for(const pair<int, int>& p: sub)
//            cout << "(" << p.first << "," << p.second << ")";
//        cout << endl;

        int n = sub.size();
        if(n <= 1) return -1;

        sort(sub.begin(), sub.end());
        vector<int> dp(n);
        dp[n - 1] = sub.back().second - sub.back().first + 1;
        for(int i = n - 2; i >= 0; i --)
            dp[i] = min(dp[i + 1], sub[i].second - sub[i].first + 1);

        int res = INT_MAX;
        for(int i = 0; i < n; i ++){
            vector<pair<int, int>>::iterator iter = upper_bound(sub.begin(), sub.end(), make_pair(sub[i].second + 1, -1));
            if(iter != sub.end()) res = min(res, sub[i].second - sub[i].first + 1 + dp[iter - sub.begin()]);
        }
        return res == INT_MAX ? -1 : res;
    }

private:
    vector<pair<int, int>> get_subarrays(const vector<int>& arr, int t){

        vector<pair<int, int>> res;
        int l = 0, r = -1, sum = 0;
        while(l < arr.size()){
            if(sum == t) res.push_back({l, r});

            if(r + 1 < arr.size() && sum < t) sum += arr[++r];
            else sum -= arr[l ++];
        }
        return res;
    }
};


int main() {

    vector<int> arr1 = {3,2,2,4,3};
    cout << Solution().minSumOfLengths(arr1, 3) << endl;
    // 2

    vector<int> arr2 = {7,3,4,7};
    cout << Solution().minSumOfLengths(arr2, 7) << endl;
    // 2

    vector<int> arr3 = {4,3,2,6,2,3,4};
    cout << Solution().minSumOfLengths(arr3, 6) << endl;
    // -1

    vector<int> arr4 = {5,5,4,4,5};
    cout << Solution().minSumOfLengths(arr4, 3) << endl;
    // -1

    vector<int> arr5 = {1, 6, 1};
    cout << Solution().minSumOfLengths(arr5, 7) << endl;
    // -1

    vector<int> arr6 = {1,2,2,3,2,6,7,2,1,4,8};
    cout << Solution().minSumOfLengths(arr6, 5) << endl;
    // 4

    vector<int> arr7 = {64,5,20,9,1,39};
    cout << Solution().minSumOfLengths(arr7, 69) << endl;
    // 6

    return 0;
}
