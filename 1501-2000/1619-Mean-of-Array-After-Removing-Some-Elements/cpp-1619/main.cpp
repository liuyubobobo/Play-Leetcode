/// Source : https://leetcode.com/problems/mean-of-array-after-removing-some-elements/
/// Author : liuyubobobo
/// Time   : 2020-10-17

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


/// Sorting
/// Time Complexity: O(nlogn)
/// Space Complexity: O(1)
class Solution {
public:
    double trimMean(vector<int>& arr) {

        sort(arr.begin(), arr.end());

        int k = arr.size() / 20, i = 0, j = arr.size() - 1, sum = 0;
        while(k --){
            sum += arr[i ++];
            sum += arr[j --];
        }
        return (accumulate(arr.begin(), arr.end(), 0) - sum) / (arr.size() * 18 / 20.0);
    }
};


int main() {

    return 0;
}
