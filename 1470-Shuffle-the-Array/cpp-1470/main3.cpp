/// Source : https://leetcode.com/problems/shuffle-the-array/
/// Author : liuyubobobo
/// Time   : 2020-06-08

#include <iostream>
#include <vector>

using namespace std;


/// Using nums[i] as a buffer storage
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {

        for(int i = 0; i < 2 * n; i ++)
            if(nums[i] > 0){
                int j = i;
                while(nums[i] > 0){
                    j = j < n ? 2 * j : 2 * (j - n) + 1;
                    swap(nums[i], nums[j]);
                    nums[j] = -nums[j];
                }
         }

        for(int& e: nums) e = -e;
        return nums;
    }
};


int main() {

    return 0;
}
