/// Source : https://leetcode.com/problems/maximum-subarray-sum-with-one-deletion/
/// Author : liuyubobobo
/// Time   : 2019-09-11

#include <iostream>
#include <vector>

using namespace std;


/// Dropped and nondropped DP, make two pass in one pass
/// Optimized in O(1) space;
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int maximumSum(vector<int>& arr) {

        int n = arr.size();
        if(n == 1) return arr[0];

        int undropped = max(arr[0] + arr[1], arr[1]);
        int dropped = max(arr[0], arr[1]);
        int res = max(undropped, dropped);
        for(int i = 2; i < n; i ++){
            dropped = max(undropped, dropped + arr[i]);
            res = max(res, dropped);

            if(undropped <= 0) undropped = arr[i];
            else undropped = arr[i] + undropped;
            res = max(res, undropped);
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