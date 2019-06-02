# Source : https://leetcode.com/problems/generate-parentheses/
# Author : penpenps
# Time   : 2019-05-28

from typing import List

# Traversal all combinations with left part length as i and right part as n-1-i 
# Time Complexity: O(2^n)
# Space Complexity: O(n)

class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        ans = []
        for i in range(n):
            left = self.generateParenthesis(i)
            if not left:
                left = [""]
            right = self.generateParenthesis(n-1-i)
            if not right:
                right = [""]
            for l in left:
                for r in right:
                    ans.append("("+l+")"+r)
        return ans

if __name__ == '__main__':
	solution = Solution()
	n = 3
	print(solution.generateParenthesis(n))