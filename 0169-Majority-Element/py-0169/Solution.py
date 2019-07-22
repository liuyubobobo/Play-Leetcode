# Source : https://leetcode.com/problems/majority-element/
# Author : penpenps
# Time   : 2019-07-22

from typing import List

# Sort nums and pick the (n/2)-th number
# Time Complexity: O(nlogn)
# Space Complexity: O(n)

class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        return sorted(nums)[len(nums)//2]
