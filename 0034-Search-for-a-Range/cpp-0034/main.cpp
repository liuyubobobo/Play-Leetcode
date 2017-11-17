/// Source : https://leetcode.com/problems/search-for-a-range/description/
/// Author : liuyubobobo
/// Time   : 2017-11-16

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

        int first = nums.size() + 1, last = -1;
        for(int i = 0 ; i < nums.size() ; i ++)
            if(nums[i] == target){
                first = min(first, i);
                last = max(last, i);
            }

        int res[2] = {first, last};
        if(first == nums.size() + 1){
            assert(last == -1);
            res[0] = res[1] = -1;
        }

        return vector<int>(res, res + 2);
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