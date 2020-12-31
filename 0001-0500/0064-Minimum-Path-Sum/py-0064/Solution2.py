# Source : https://leetcode.com/problems/minimum-path-sum/
# Author : penpenps
# Time   : 2019-07-10

from typing import List

# Use two m-length list to keep last iteration and current iteration result
# Time Complexity: O(n*m)
# Space Complexity: O(2*n)
class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        if not grid or not grid[0]: 
            return 0
        n = len(grid)
        m = len(grid[0])
        dp = [[0]*m for _ in range(2)]
        dp[0][0] = grid[0][0]
        for i in range(1, m):
            dp[0][i] = dp[0][i-1] + grid[0][i]
        
        for i in range(1, n):
            dp[i%2][0] = dp[(i-1)%2][0] + grid[i][0]
            for j in range(1, m):
                dp[i%2][j] = min(dp[(i-1)%2][j], dp[i%2][j-1]) + grid[i][j]
        
        return dp[(n-1)%2][m-1]

if __name__ == '__main__':
    solution = Solution()
    grid = [
    [1,3,1],
    [1,5,1],
    [4,2,1]
    ]
    print(solution.minPathSum(grid))