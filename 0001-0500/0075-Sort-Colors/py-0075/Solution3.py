# Source : https://leetcode.com/problems/sort-colors/
# Author : penpenps
# Time   : 2019-05-31

from typing import List

# use [i, j) to keep 0, [j, k) keeps 1 and [k, ] keeps 2
# Time Complexity: O(n)
# Space Complexity: O(4)

class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        i, j, k = 0, 0, 0
        for k in range(len(nums)):
            v = nums[k]
            nums[k] = 2
            if v < 2:
                nums[j] = 1
                j += 1
            if v < 1:
                nums[i] = 0
                i += 1
        

if __name__ == '__main__':
	s = Solution()
	nums = [2,0,2,1,1,0]
	s.sortColors(nums)
	print(nums)
