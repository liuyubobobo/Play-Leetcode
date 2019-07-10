# Source : https://leetcode.com/problems/minimum-path-sum/
# Author : penpenps
# Time   : 2019-07-10

from typing import List

# Use single list to keep accumulate dp result
# Time Complexity: O(n*m)
# Space Complexity: O(n)
class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        if not grid or not grid[0]: 
            return 0
        n = len(grid)
        m = len(grid[0])
        dp = [0]*m
        dp[0] = grid[0][0]
        for i in range(1, m):
            dp[i] = dp[i-1] + grid[0][i]
        
        for i in range(1, n):
            dp[0] += grid[i][0]
            for j in range(1, m):
                dp[j] = min(dp[j-1], dp[j]) + grid[i][j]
        
        return dp[m-1]

if __name__ == '__main__':
    solution = Solution()
    grid = [
    [1,3,1],
    [1,5,1],
    [4,2,1]
    ]
    print(solution.minPathSum(grid))