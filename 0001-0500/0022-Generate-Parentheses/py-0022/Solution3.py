# Source : https://leetcode.com/problems/generate-parentheses/
# Author : penpenps
# Time   : 2019-05-28

from typing import List

# Traversal all combinations with left part length as i and right part as n-1-i 
# Time Complexity: O(2^n)
# Space Complexity: O(n)

class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        dp = [[] for _ in range(n+1)]
        dp[0] = [""]
        for i in range(1, n+1):
            for j in range(i):
                for l in dp[j]:
                    for r in dp[i-j-1]:
                        dp[i].append("("+l+")"+r)
        return dp[n]

if __name__ == '__main__':
    solution = Solution()
    n = 3
    print(solution.generateParenthesis(n))