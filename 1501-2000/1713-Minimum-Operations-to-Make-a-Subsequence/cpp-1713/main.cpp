/// Source : https://leetcode.com/problems/minimum-operations-to-make-a-subsequence/
/// Author : liuyubobobo
/// Time   : 2021-01-02

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


/// LIS
/// Time Complexity: O(|target| + |arr| * log|arr|)
/// Space Complexity: O(|target| + |arr|)
class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {

        unordered_map<int, int> map;
        for(int i = 0; i < target.size(); i ++)
            map[target[i]] = i;

        vector<int> v;
        for(int e: arr)
            if(map.count(e)) v.push_back(map[e]);

        // LIS
        vector<int> dp;
        for(int e: v)
            if(dp.empty() || e > dp.back()) dp.push_back(e);
            else{
                vector<int>::iterator iter = lower_bound(dp.begin(), dp.end(), e);
                dp[iter - dp.begin()] = e;
            }
        return target.size() - dp.size();
    }
};


int main() {

    vector<int> target1 = {5, 1, 3}, arr1 = {9, 4, 2, 3, 4};
    cout << Solution().minOperations(target1, arr1) << endl;
    // 2

    vector<int> target2 = {6,4,8,1,3,2}, arr2 = {4,7,6,2,3,8,6,1};
    cout << Solution().minOperations(target2, arr2) << endl;
    // 3

    return 0;
}
