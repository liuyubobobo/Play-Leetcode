# Source : https://leetcode.com/problems/sort-colors/
# Author : penpenps
# Time   : 2019-05-31

from typing import List

# Counting and reset nums in order
# Time Complexity: O(2*n)
# Space Complexity: O(3)

class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        m = [0]*3
        for x in nums:
            m[x] += 1
            
        for i in range(len(nums)):
            if i < m[0]:
                nums[i] = 0
            if m[0] <= i < m[1] + m[0]:
                nums[i] = 1
            if i >= m[0] + m[1]:
                nums[i] = 2
        

if __name__ == '__main__':
	s = Solution()
	nums = [2,0,2,1,1,0]
	s.sortColors(nums)
	print(nums)
