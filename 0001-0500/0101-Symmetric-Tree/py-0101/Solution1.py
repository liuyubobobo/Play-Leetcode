# Source : https://leetcode.com/problems/symmetric-tree/
# Author : penpenps
# Time   : 2019-07-09

# Revert right node firstly, then compare with left node
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
        # Revert TreeNode
        def revert(node):
            if not node: return
            node.left, node.right = node.right, node.left
            revert(node.left)
            revert(node.right)
        
        def isEqual(left, right):
            if not left and not right: return True
            if not left or not right: return False
            if left.val != right.val:
                return False
            return isEqual(left.left, right.left) and isEqual(left.right, right.right)
        
        if not root:
            return True
        revert(root.right)
        return isEqual(root.left, root.right)
