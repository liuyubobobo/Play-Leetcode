# Source : https://leetcode.com/problems/monotonic-array/
# Author : penpenps
# Time   : 2019-07-29

from typing import List

# Two pass
# Time Complexity: O(n)
# Space Complexity: O(1)

class Solution:
    def isMonotonic(self, A: List[int]) -> bool:
        n = len(A)
        i = 1
        while i < n:
            if A[i] > A[i-1]:
                break
            i += 1
        if i == n:
            return True
        i = 1
        while i < n:
            if A[i] < A[i-1]:
                break
            i += 1
        if i == n:
            return True
        return False