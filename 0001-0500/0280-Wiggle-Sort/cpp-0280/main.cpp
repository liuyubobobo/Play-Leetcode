/// Source : https://leetcode.com/problems/wiggle-sort/description/
/// Author : liuyubobobo
/// Time   : 2023-02-08

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/// Ad-Hoc
/// Time Complexity: O(nlogn)
/// Space Complexity: O(1)
class Solution {
public:
    void wiggleSort(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        for(int i = 1; i + 1 < nums.size(); i += 2)
            swap(nums[i], nums[i + 1]);
    }
};


int main() {

    return 0;
}
