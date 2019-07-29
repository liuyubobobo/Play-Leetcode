# Source : https://leetcode.com/problems/maximal-square/
# Author : penpenps
# Time   : 2019-07-24

from typing import List

# DP solution, dp[i][i] represents the length of largest square end with matrix[i][j]
# Then, dp[i][j] = min(dp[i-1][j-1], dp[i][j-1], dp[i-1][j]) + 1
# Time Complexity: O(n^2)
# Space Complexity: O(n^2)

class Solution:
    def maximalSquare(self, matrix: List[List[str]]) -> int:
        if not matrix or not matrix[0]: return 0
        n = len(matrix)
        m = len(matrix[0])
        
        dp = [[1 if matrix[i][j] == '1' else 0 for j in range(m)] for i in range(n)]

        for i in range(1, n):
            for j in range(1, m):
                if matrix[i][j] == '1':
                    dp[i][j] = min(dp[i-1][j-1], dp[i][j-1], dp[i-1][j]) + 1
        return max(max(row) for row in dp)**2