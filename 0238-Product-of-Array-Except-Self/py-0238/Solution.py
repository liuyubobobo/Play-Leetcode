# Source : https://leetcode.com/problems/product-of-array-except-self/
# Author : penpenps
# Time   : 2019-08-01

from typing import List

# For i-th element, the product except itself equals product of 0 to i-1 and i+1 element to the end
# We can get left and right accumlate product for each index by traversaling from 0 to the end and reverse once again
# Time Complexity: O(n)
# Space Complexity: O(n)

class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        left, right = [_ for _ in nums], [_ for _ in nums]
        n = len(nums)
        for i in range(1, n):
            left[i] *= left[i-1]
        for i in range(n-2, -1, -1):
            right[i] *= right[i+1]
        
        ans = [0]*n
        for i in range(n):
            left_part = left[i-1] if i > 0 else 1
            right_part = right[i+1] if i < n-1 else 1
            ans[i] = left_part * right_part
        return ans
