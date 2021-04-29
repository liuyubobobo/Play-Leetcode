/// Source : https://leetcode.com/problems/search-for-a-range/description/
/// Author : liuyubobobo
/// Time   : 2017-11-16
/// Updated: 2021-04-29

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

/// Linear Scan
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        bool ok = false;
        int first = nums.size(), last = -1;
        for(int i = 0 ; i < nums.size() ; i ++)
            if(nums[i] == target){
                first = min(first, i);
                last = max(last, i);
                ok = true;
            }

        if(ok) return {first, last};
        return {-1, -1};
    }
};


void printVec(const vector<int>& vec){
    for(int e: vec)
        cout << e << " ";
    cout << endl;
}

int main() {

    int nums[6] = {5, 7, 7, 8, 8, 10};
    int target = 8;
    vector<int> vec(nums, nums + sizeof(nums) / sizeof(int));

    printVec(Solution().searchRange(vec, target));

    return 0;
}