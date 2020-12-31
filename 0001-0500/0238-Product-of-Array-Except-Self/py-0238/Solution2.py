# Source : https://leetcode.com/problems/product-of-array-except-self/
# Author : penpenps
# Time   : 2019-08-01

from typing import List

# Construct answer the same way we build left part array like solution #1 and then reversly multiple one by one to get the corresponding right part product value
# Time Complexity: O(n)
# Space Complexity: O(1)

class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        ans = [1]*n
        for i in range(1, n):
            ans[i] = ans[i-1]*nums[i-1]
        R = 1
        for i in range(n-1, -1, -1):
            ans[i] = ans[i]*R
            R *= nums[i]
        return ans