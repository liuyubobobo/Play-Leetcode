/// Source : https://leetcode.com/problems/missing-number-in-arithmetic-progression/
/// Author : liuyubobobo
/// Time   : 2019-10-19

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;


/// Binary Search
/// Time Complexity: O(logn)
/// Space Complexity: O(1)
class Solution {
public:
    int missingNumber(vector<int>& arr) {

        int d = (arr.back() - arr[0]) / (int)arr.size();
        int l = 0, r = arr.size() - 1;
        while(l < r){
            int mid = (l + r) / 2;
            int num = arr[0] + mid * d;
            if(num != arr[mid])
                r = mid;
            else
                l = mid + 1;
        }
        return arr[l] - d;
    }
};


int main() {

    vector<int> arr1 = {15, 13, 12};
    cout << Solution().missingNumber(arr1) << endl;
    // 14

    return 0;
}