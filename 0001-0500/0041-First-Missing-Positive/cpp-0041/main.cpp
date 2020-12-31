/// Source : https://leetcode.com/problems/first-missing-positive/
/// Author : liuyubobobo
/// Time   : 2019-02-07

#include <iostream>
#include <vector>

using namespace std;


/// Index as a hash key
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {

        int n = nums.size(), cur = 0;
        for(int i = 0; i < n; i ++)
            if(nums[i] <= 0)
                swap(nums[i--], nums[--n]);

        //nums[0...n) are all positives
//        for(int e: nums)
//            cout << e << " ";
//        cout << endl;
//        cout << "size = " << n << endl;

        for(int i = 0; i < n; i ++)
            if(abs(nums[i]) - 1 < n && nums[abs(nums[i]) - 1] > 0)
                nums[abs(nums[i]) - 1] *= -1;
        // nums[i] < 0 means there exists i + 1
//        for(int e: nums)
//            cout << e << " ";
//        cout << endl;

        for(int i = 0; i < n; i ++)
            if(nums[i] > 0)
                return i + 1;
        return n + 1;
    }
};


int main() {

    vector<int> nums = {3, 4, -1, 1};
    cout << Solution().firstMissingPositive(nums) << endl;
    // 2

    return 0;
}