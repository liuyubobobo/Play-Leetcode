# Source : https://leetcode.com/problems/symmetric-tree/
# Author : penpenps
# Time   : 2019-07-09

# Use single queue to store left and right subtree elements in different directions
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
        q = [root, root]
        while q:
            n1, n2 = q.pop(), q.pop()
            if not n1 and not n2:
                continue
            if not n1 or not n2:
                return False
            if n1.val != n2.val:
                return False
            q.append(n1.left)
            q.append(n2.right)
            q.append(n1.right)
            q.append(n2.left)
        return True