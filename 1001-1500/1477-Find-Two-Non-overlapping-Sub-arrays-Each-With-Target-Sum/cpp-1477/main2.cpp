/// Source : https://leetcode.com/problems/maximum-students-taking-exam/
/// Author : liuyubobobo
/// Time   : 2020-06-13

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


/// Presum + Dynamic Programming
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {

public:
    int minSumOfLengths(vector<int>& arr, int target) {

        unordered_map<int, int> presum;
        presum[0] = 0;

        vector<int> dp = {INT_MAX};
        int pre= 0, res = INT_MAX;
        for(int i = 0; i < arr.size(); i ++){
            int sum = arr[i] + pre;
            pre = sum;
            presum[sum] = i + 1;
            if(presum.count(sum - target)){
                int index = presum[sum - target];
                if(dp[index] != INT_MAX) res = min(res, i - index + 1 + dp[index]);
                dp.push_back(min(dp.back(), i - index + 1));
            }
            else dp.push_back(dp.back());
        }
        return res == INT_MAX ? -1 : res;
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

    vector<int> arr8 = {47,17,4,8,8,2,1,1,8,35,30,1,11,1,1,1,44,1,3,27,2,8};
    cout << Solution().minSumOfLengths(arr8, 88) << endl;
    // 16

    return 0;
}
