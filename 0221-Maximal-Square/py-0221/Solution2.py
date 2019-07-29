# Source : https://leetcode.com/problems/maximal-square/
# Author : penpenps
# Time   : 2019-07-24

from typing import List

# modify matrix in-place
# Time Complexity: O(n^2)
# Space Complexity: O(1)

class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        if not matrix or not matrix[0]: return 0
        n = len(matrix)
        m = len(matrix[0])
        
        for i in range(n):
            matrix[i][0] = 1 if matrix[i][0] == '1' else 0 
        for j in range(1, m):
            matrix[0][j] = 1 if matrix[0][j] == '1' else 0 
        
        for i in range(1, n):
            for j in range(1, m):
                if matrix[i][j] == '1':
                    matrix[i][j] = min(matrix[i-1][j-1], matrix[i][j-1], matrix[i-1][j]) + 1
                else:
                    matrix[i][j] = 0
        return max(max(row) for row in matrix)**2