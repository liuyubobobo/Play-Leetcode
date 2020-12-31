# Source : https://leetcode.com/problems/maximum-product-subarray/
# Author : penpenps
# Time   : 2019-07-21

from typing import List

# If even number of elements, the max product is multiple all nums together
# If odd number, it should be divided into to part from one of the negative numbers and the answer is one of two seperated parts to multiple together
# Time Complexity: O(n)
# Space Complexity: O(1)

class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        n = len(nums)
        rnums = nums[::-1]
        for i in range(1, n):
            nums[i] *= nums[i-1] or 1
            rnums[i] *= rnums[i-1] or 1

        return max(nums + rnums)
        

if __name__ == '__main__':
	s = Solution()
	nums = [2,3,-2,4]
	answer = s.maxProduct(nums)
	print(answer)
