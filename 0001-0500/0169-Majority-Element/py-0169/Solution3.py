# Source : https://leetcode.com/problems/majority-element/
# Author : penpenps
# Time   : 2019-07-22

from typing import List

# Randomly pick one to check whether the answer
# Time Complexity: Worst: O(infinity) Average: O(n)
# Space Complexity: O(1)

import random
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        def occurance(nums, target):
            return sum(1 if x == target else 0 for x in nums)
        
        n = len(nums)
        while True:
            index = random.randint(0, n-1)
            if occurance(nums, nums[index]) >= n / 2:
                return nums[index]
