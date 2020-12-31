/// Source : https://leetcode.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/
/// Author : liuyubobobo
/// Time   : 2020-02-19

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


/// Sliding Window
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {

        int sum = accumulate(arr.begin(), arr.begin() + (k - 1), 0), res = 0;
        for(int i = k - 1; i < arr.size(); i ++){
            sum += arr[i];
            if(sum >= k * threshold) res ++;
            sum -= arr[i - (k - 1)];
        }
        return res;
    }
};


int main() {

    return 0;
}
