/// Source : https://leetcode.com/problems/missing-number-in-arithmetic-progression/
/// Author : liuyubobobo
/// Time   : 2019-10-19

#include <iostream>
#include <vector>

using namespace std;


/// Linear Scan and find the max gap between numbers
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int missingNumber(vector<int>& arr) {

        int maxGap = arr[1] - arr[0], start = 0;
        for(int i = 2; i < arr.size(); i ++)
            if(abs(arr[i] - arr[i - 1]) > abs(maxGap)){
                maxGap = arr[i] - arr[i - 1];
                start = i -1;
            }
        return arr[start] + maxGap / 2;
    }
};


int main() {

    return 0;
}