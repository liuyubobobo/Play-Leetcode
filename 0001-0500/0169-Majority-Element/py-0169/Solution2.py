# Source : https://leetcode.com/problems/majority-element/
# Author : penpenps
# Time   : 2019-07-22

from typing import List

# Count occurance for each number and find out the one whose occurance more than n/2 times
# Time Complexity: O(n)
# Space Complexity: O(n)

import collections
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        m = collections.Counter(nums)
        n = len(nums)
        for k,v in m.items():
            if v >= n/2:
                return k
