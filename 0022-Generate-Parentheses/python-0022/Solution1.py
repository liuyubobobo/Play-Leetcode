# Source : https://leetcode.com/problems/generate-parentheses/
# Author : penpenps
# Time   : 2019-05-28

from typing import List

# Recursive with "(" and ")" separately and guarantee open and close num is equal
# Time Complexity: O(2^n)
# Space Complexity: O(n)

class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        def helper(current, openNum, closeNum, n, ans):
            if len(current) == 2*n:
                ans.append(current)
                return
            if openNum < n:
                helper(current+"(", openNum + 1, closeNum, n, ans)
            if closeNum < openNum:
                helper(current+")", openNum, closeNum + 1, n, ans)
                
        ans = []
        helper("", 0, 0, n, ans)
        return ans

if __name__ == '__main__':
	solution = Solution()
	n = 3
	print(solution.generateParenthesis(n))