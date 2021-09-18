/// Source : https://leetcode.com/problems/count-number-of-pairs-with-absolute-difference-k/
/// Author : liuyubobobo
/// Time   : 2021-09-18

#include <iostream>
#include <vector>

using namespace std;


/// Sorting + Binary Search
/// Time Complexity: O(nlogn)
/// Space Complexity: O(1)
class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {

        sort(nums.begin(), nums.end());
        int res = 0;
        for(int e: nums){
            vector<int>::iterator iter1 = lower_bound(nums.begin(), nums.end(), e + k);
            if(iter1 == nums.end() || *iter1 != e + k) continue;

            vector<int>::iterator iter2 = upper_bound(nums.begin(), nums.end(), e + k);
            res += (iter2 - iter1);
        }
        return res;
    }
};


int main() {

    return 0;
}
