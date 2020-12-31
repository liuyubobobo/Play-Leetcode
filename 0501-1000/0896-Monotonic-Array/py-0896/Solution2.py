# Source : https://leetcode.com/problems/monotonic-array/
# Author : penpenps
# Time   : 2019-07-29

from typing import List

# One pass
# Time Complexity: O(n)
# Space Complexity: O(1)

class Solution:
    def isMonotonic(self, A: List[int]) -> bool:
        n = len(A)
        trend = 0
        for i in range(1, n):
            if trend == 0:
                if A[i] > A[i-1]:
                    trend = 1
                elif A[i] < A[i-1]:
                    trend = -1
            elif trend * (A[i] - A[i-1]) < 0:
                return False
        return True