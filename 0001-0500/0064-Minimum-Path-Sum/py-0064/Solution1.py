# Source : https://leetcode.com/problems/minimum-path-sum/
# Author : penpenps
# Time   : 2019-07-10

from typing import List

# Straght-forward dp solution, dp[i][j] means the min distance from position [0][0] to [i][j]
# Time Complexity: O(n*m)
# Space Complexity: O(n*m)

class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        if not grid or not grid[0]: 
            return 0
        n = len(grid)
        m = len(grid[0])
        dp = [[0]*m for _ in range(n)]
        dp[0][0] = grid[0][0]
        for i in range(1, m):
            dp[0][i] = dp[0][i-1] + grid[0][i]
        for j in range(1, n):
            dp[j][0] = dp[j-1][0] + grid[j][0]
        
        for i in range(1, n):
            for j in range(1, m):
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j]
        
        return dp[n-1][m-1]

if __name__ == '__main__':
    solution = Solution()
    grid = [
    [1,3,1],
    [1,5,1],
    [4,2,1]
    ]
    print(solution.minPathSum(grid))