/// Source : https://leetcode.com/problems/maximum-subarray-sum-with-one-deletion/
/// Author : liuyubobobo
/// Time   : 2019-09-11

#include <iostream>
#include <vector>

using namespace std;


/// Dropped and nondropped DP, make two pass in one pass
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    int maximumSum(vector<int>& arr) {

        int n = arr.size();
        if(n == 1) return arr[0];

        vector<int> undropped(n, 0), dropped(n, 0);
        undropped[0] = arr[0], undropped[1] = max(arr[0] + arr[1], arr[1]);
        dropped[1] = max(arr[0], arr[1]);
        int res = max(undropped[1], dropped[1]);
        for(int i = 2; i < n; i ++){
            if(undropped[i - 1] <= 0) undropped[i] = arr[i];
            else undropped[i] = arr[i] + undropped[i - 1];
            res = max(res, undropped[i]);

            dropped[i] = max(undropped[i - 1], dropped[i - 1] + arr[i]);
            res = max(res, dropped[i]);
        }
        return res;
    }
};


int main() {

    vector<int> arr1 = {1, -2, 0, 3};
    cout << Solution().maximumSum(arr1) << endl;
    // 4

    vector<int> arr2 = {1, -2, -2, 3};
    cout << Solution().maximumSum(arr2) << endl;
    // 3

    vector<int> arr3 = {-1, -1, -1, -1};
    cout << Solution().maximumSum(arr3) << endl;
    // -1

    vector<int> arr4 = {8, -1, 6, -7, -4, 5, -4, 7, -6};
    cout << Solution().maximumSum(arr4) << endl;
    // 17

    return 0;
}