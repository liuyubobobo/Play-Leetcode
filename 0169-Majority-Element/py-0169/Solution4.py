# Source : https://leetcode.com/problems/majority-element/
# Author : penpenps
# Time   : 2019-07-22

from typing import List

# Recursivly divide two half parts and search most occurance number
# Time Complexity: O(nlogn)
# Space Complexity: O(logn)

class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        def occurance(nums, left, right, target):
            return sum(1 if x == target else 0 for x in nums[left:right+1])
        def helper(nums, left, right):
            length = right - left + 1
            if length <= 2:
                return nums[left]
            mid = (left+right) // 2
            leftMaj = helper(nums, left, mid)
            rightMaj = helper(nums, mid+1, right)
            if leftMaj == rightMaj:
                return leftMaj
            leftMajCnt = occurance(nums, left, mid, leftMaj)
            rightMajCnt = occurance(nums, mid+1, right, rightMaj)
            
            return leftMaj if leftMajCnt > rightMajCnt else rightMaj
        return helper(nums, 0, len(nums)-1)
