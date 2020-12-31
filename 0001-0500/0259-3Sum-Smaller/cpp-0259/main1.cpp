/// Source : https://leetcode.com/problems/3sum-smaller/
/// Author : liuyubobobo
/// Time   : 2016-12-05

#include <iostream>
#include <vector>
#include <cassert>
#include <stdexcept>

using namespace std;


/// Binary Search
/// Sort the entire numbers first.
/// For every number nums[i] and nums[j] in numbers,
/// use binary search to find index k,
/// which makes nums[i] + nums[j] + nums[k] is the closest sum less than the target.
///
/// Time Complexity: O(nlogn) + O((n^2)logn)
/// Space Complexity: O(1)
class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {

        // There're testcases which the nums.size < 3
        //assert( nums.size() >= 3 );
        if( nums.size() < 3 )
            return 0;

        sort(nums.begin(), nums.end());

        int res = 0;
        for( int i = 0 ; i < nums.size() - 2 ; i ++ ){
            for( int j = i + 1 ; j < nums.size() - 1 ; j ++ ){
                int t = target - nums[i] - nums[j];

                // find the largest index in nums[j+1...nums.size()-1]
                // where nums[index] < t
                int index = bsearch(nums, j+1, nums.size() - 1, t);

                if(index != -1)
                    res += (index - j);
            }
        }
        return res;
    }

private:
    // find the largest index j in the range [l...r] where nums[j] < target
    // return -1 if there's no element less than the given target
    int bsearch(const vector<int> &nums, int l, int r, int target){

        assert(l >= 0 && r < nums.size() && l <= r);

        // the left point is l-1 to give the space for non solution.
        int left = l-1, right = r;
        while(left != right){

            // Using round-up tecnique to avoid inifinite loop
            int mid = left + (right - left + 1) / 2;

            if(nums[mid] >= target)
                right = mid - 1;
            else
                left = mid;
        }

        if(left <= l - 1)
            return -1;

        return left;
    }
};


int main() {

    vector<int> nums1 = {-2, 0, 1, 3};
    int target1 = 4;
    cout << Solution().threeSumSmaller(nums1, target1) << endl;

    return 0;
}