# Source : https://leetcode.com/problems/sort-colors/
# Author : penpenps
# Time   : 2019-05-31

from typing import List

# Quick sort for 3 numbers
# Time Complexity: O(n)
# Space Complexity: O(3)

class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        zero = 0
        two = len(nums) - 1
        i = 0
        while i <= two:
            if nums[i] == 0:
                nums[i], nums[zero] = nums[zero], nums[i]
                zero += 1
                i += 1
            elif nums[i] == 2:
                nums[i], nums[two] = nums[two], nums[i]
                two -= 1
            else:
                i += 1
        

if __name__ == '__main__':
	s = Solution()
	nums = [2,0,2,1,1,0]
	s.sortColors(nums)
	print(nums)
