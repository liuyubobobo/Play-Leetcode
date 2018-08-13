/// Source : https://leetcode.com/problems/3sum-closest/
/// Author : liuyubobobo
/// Time   : 2016-12-03

#include <iostream>
#include <vector>
#include <cassert>
#include <stdexcept>

using namespace std;


/// Sorting + Two Pointers
/// Time Complexity: O(nlogn) + O(n^2)
/// Space Complexity: O(1)
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        assert(nums.size() >= 3);

        sort(nums.begin(), nums.end());

        int diff = abs(nums[0] + nums[1] + nums[2] - target);
        int res = nums[0] + nums[1] + nums[2];

        for(int i = 0 ; i < nums.size() ; i ++){

            int l = i + 1, r = nums.size() - 1;
            int t = target - nums[i];
            while(l < r){
                if(nums[l] + nums[r] == t)
                    return nums[i] + nums[l] + nums[r];
                else{

                    if(abs(nums[l] + nums[r] - t) < diff){
                        diff = abs(nums[l] + nums[r] - t);
                        res = nums[i] + nums[l] + nums[r];
                    }

                    if( nums[l] + nums[r] < t )
                        l ++;
                    else   // nums[l] + nums[r] > t
                        r --;
                }
            }
        }

        return res;
    }
};


int main() {

    vector<int> nums1 = {0, 0, 0};
    int target1 = 1;
    cout << Solution().threeSumClosest(nums1, target ) << endl;

    return 0;
}