/// Source : https://leetcode.com/problems/missing-number-in-arithmetic-progression/
/// Author : liuyubobobo
/// Time   : 2019-10-19

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;


/// Using mathematics to calculate difference first
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int missingNumber(vector<int>& arr) {

        int d = (arr.back() - arr[0]) / (int)arr.size();
        for(int i = 1; i < arr.size(); i ++)
            if(arr[i] != arr[i - 1] + d) return arr[i - 1] + d;

        // a tricky case is d == 0
        assert(d == 0);
        return arr[0];
    }
};


int main() {

    vector<int> arr1 = {15, 13, 12};
    cout << Solution().missingNumber(arr1) << endl;

    return 0;
}