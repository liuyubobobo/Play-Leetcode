/// Source : https://leetcode.com/problems/maximum-element-after-decreasing-and-rearranging/
/// Author : liuyubobobo
/// Time   : 2021-05-01

#include <iostream>
#include <vector>

using namespace std;


/// Sorting and Greedy
/// Time Complexity: O(nlogn)
/// Space Complexity: O(1)
class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {

        sort(arr.begin(), arr.end());
        arr[0] = 1;
        for(int i = 1; i < arr.size(); i ++)
            arr[i] = min(arr[i - 1] + 1, arr[i]);
        return arr.back();
    }
};


int main() {

    vector<int> arr1 = {2, 2, 1, 2, 1};
    cout << Solution().maximumElementAfterDecrementingAndRearranging(arr1) << endl;
    // 2

    return 0;
}
