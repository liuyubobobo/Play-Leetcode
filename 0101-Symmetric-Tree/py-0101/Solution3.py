# Source : https://leetcode.com/problems/symmetric-tree/
# Author : penpenps
# Time   : 2019-07-09

# Level traversal using two queues to keep left and right sub-tree
# Time Complexity: O(n)
# Space Complexity: O(n)

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        if not root:
            return True
        q1, q2 = [root], [root]
        while q1 and q2:
            n1, n2 = q1.pop(), q2.pop()
            if not n1 and not n2:
                continue
            if not n1 or not n2:
                return False
            if n1.val != n2.val:
                return False
            q1.append(n1.left)
            q1.append(n1.right)
            q2.append(n2.right)
            q2.append(n2.left)
        return not q1 and not q2