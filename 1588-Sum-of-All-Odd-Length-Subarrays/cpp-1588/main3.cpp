/// Source : https://leetcode-cn.com/problems/sum-of-all-odd-length-subarrays/
/// Author : liuyubobobo
/// Time   : 2020-09-19

#include <iostream>
#include <vector>

using namespace std;


/// Mathematics
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {

        int res = 0;
        for(int i = 0; i < arr.size(); i ++){
            int left = i + 1, right = arr.size() - i,
                left_even = (left + 1) / 2, right_even = (right + 1) / 2,
                left_odd = left / 2, right_odd = right / 2;
            res += (left_even * right_even + left_odd * right_odd) * arr[i];
        }
        return res;
    }
};


int main() {

    vector<int> arr1 = {1, 4, 2, 5, 3};
    cout << Solution().sumOddLengthSubarrays(arr1) << endl;
    // 58

    vector<int> arr2 = {1, 2};
    cout << Solution().sumOddLengthSubarrays(arr2) << endl;
    // 3

    vector<int> arr3 = {10,11,12};
    cout << Solution().sumOddLengthSubarrays(arr3) << endl;
    // 66

    return 0;
}
