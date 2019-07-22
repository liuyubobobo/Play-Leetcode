# Source : https://leetcode.com/problems/majority-element/
# Author : penpenps
# Time   : 2019-07-22

from typing import List

# Boyer-Moore Voting Algorithm, count for one number, if not equal to current number, count minus 1 until ot 0 then try another number
# Time Complexity: O(n)
# Space Complexity: O(1)

class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        ans = nums[0]
        count = 0
        for n in nums:
            if count == 0:
                ans = n
                count += 1
            elif n == ans:
                count += 1
            else:
                count -= 1
        return ans
