# Source : https://leetcode.com/problems/maximum-product-subarray/
# Author : penpenps
# Time   : 2019-07-21

from typing import List

# Travesal nums, use maxVal and minVal to keep max and min product end with current element
# Time Complexity: O(n)
# Space Complexity: O(1)

class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        n = len(nums)
        minVal, maxVal = nums[0], nums[0]
        ans = nums[0]
        for i in range(1, n):
            # If negative number, it should swap min and max for sign switching
            if nums[i] < 0:
                minVal, maxVal = maxVal, minVal
            maxVal = max(nums[i]*maxVal, nums[i])
            minVal = min(nums[i]*minVal, nums[i])
            ans = max(maxVal, ans)

        return ans
        

if __name__ == '__main__':
	s = Solution()
	nums = [2,3,-2,4]
	answer = s.maxProduct(nums)
	print(answer)
