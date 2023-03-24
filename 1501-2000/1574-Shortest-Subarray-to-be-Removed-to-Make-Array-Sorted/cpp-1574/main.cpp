/// Source : https://leetcode.com/problems/shortest-subarray-to-be-removed-to-make-array-sorted/description/
/// Author : liuyubobobo
/// Time   : 2023-03-24

#include <iostream>
#include <vector>
#include <map>

using namespace std;


/// Using Map
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {

public:
    int findLengthOfShortestSubarray(vector<int>& arr) {

        if(is_sorted(arr.begin(), arr.end())) return 0;

        int n = arr.size();

        map<int, int> table;
        table[arr[n - 1]] = n - 1;
        int res = 1;
        for(int i = n - 2; i >= 0 && arr[i] <= arr[i + 1]; i --)
            table[arr[i]] = i, res = n - i;

        for(int i = 0; i < n && (i == 0 || arr[i] >= arr[i - 1]); i ++){
            res = max(res, i + 1);
            auto iter = table.lower_bound(arr[i]);
            if(iter != table.end()){
                int j = iter->second;
                res = max(res, i + 1 + (n - j));
            }
        }
        return n - res;
    }
};


int main() {

    vector<int> arr1 = {1, 2, 3, 10, 4, 2, 3, 5};
    cout << Solution().findLengthOfShortestSubarray(arr1) << '\n';
    // 3

    vector<int> arr2 = {5, 4, 3, 2, 1};
    cout << Solution().findLengthOfShortestSubarray(arr2) << '\n';
    // 4

    vector<int> arr3 = {2, 2, 2, 1, 1, 1};
    cout << Solution().findLengthOfShortestSubarray(arr3) << '\n';
    // 3

    vector<int> arr4 = {1, 2, 3};
    cout << Solution().findLengthOfShortestSubarray(arr4) << '\n';
    // 0

    vector<int> arr5 = {10, 13, 17, 21, 15, 15, 9, 17, 22, 22, 13};
    cout << Solution().findLengthOfShortestSubarray(arr5) << '\n';
    // 7

    vector<int> arr6 = {16, 10, 0, 3, 22, 1, 14, 7, 1, 12, 15};
    cout << Solution().findLengthOfShortestSubarray(arr6) << '\n';
    // 8

    vector<int> arr7 = {22, 0, 23, 23, 27, 23, 12, 19, 18, 10, 25, 29, 15, 28, 0};
    cout << Solution().findLengthOfShortestSubarray(arr7) << '\n';
    // 14

    return 0;
}
