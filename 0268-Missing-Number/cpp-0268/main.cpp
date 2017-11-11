/// Source : https://leetcode.com/problems/missing-number/description/
/// Author : liuyubobobo
/// Time   : 2017-11-10

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/// Sort and Check
/// Time Complexity:  O(nlogn)
/// Space Complexity: O(1)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = -1;
        for(int i = 0 ; i < nums.size() ; i ++)
            if(nums[i] != i){
                res = i;
                break;
            }
        return res == -1 ? nums.size() : res;
    }
};

int main() {

    int nums[3] = {0, 1, 3};
    vector<int> vec(nums, nums + 3);
    cout << Solution().missingNumber(vec) << endl;

    return 0;
}