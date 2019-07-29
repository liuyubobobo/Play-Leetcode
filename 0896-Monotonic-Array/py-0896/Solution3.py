# Source : https://leetcode.com/problems/monotonic-array/
# Author : penpenps
# Time   : 2019-07-29

from typing import List

# One-line solution
# Time Complexity: O(n)
# Space Complexity: O(1)

class Solution:
    def isMonotonic(self, A: List[int]) -> bool:
        return not {(x>y) - (y>x) for x, y in zip(A, A[1:])} >= {1, -1}