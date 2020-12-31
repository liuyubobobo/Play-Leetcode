# Source : https://leetcode.com/problems/minimum-path-sum/
# Author : penpenps
# Time   : 2019-07-10

from typing import List

# Update min distance in-place
# Time Complexity: O(n*m)
# Space Complexity: O(1)
class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        if not grid or not grid[0]: 
            return 0
        n = len(grid)
        m = len(grid[0])
        for i in range(1, m):
            grid[0][i] += grid[0][i-1]
        
        for i in range(1, n):
            grid[i][0] += grid[i-1][0]
            for j in range(1, m):
                grid[i][j] = min(grid[i][j-1], grid[i-1][j]) + grid[i][j]
        
        return grid[n-1][m-1]

if __name__ == '__main__':
    solution = Solution()
    grid = [
    [1,3,1],
    [1,5,1],
    [4,2,1]
    ]
    print(solution.minPathSum(grid))