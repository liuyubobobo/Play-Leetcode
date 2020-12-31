/// Source : https://leetcode.com/problems/minimum-absolute-difference/
/// Author : liuyubobobo
/// Time   : 2019-09-21

#include <iostream>
#include <vector>

using namespace std;


/// Sorting and Two Passes
/// Time Complexity: O(nlogn)
/// Space Complexity: O(1)
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {

        sort(arr.begin(), arr.end());
        int diff = INT_MAX;
        for(int i = 1; i < arr.size(); i ++)
            diff = min(diff, arr[i] - arr[i - 1]);

        vector<vector<int>> res;
        for(int i = 1; i < arr.size(); i ++)
            if(arr[i] - arr[i - 1] == diff) res.push_back({arr[i - 1], arr[i]});
        return res;
    }
};


int main() {

    return 0;
}