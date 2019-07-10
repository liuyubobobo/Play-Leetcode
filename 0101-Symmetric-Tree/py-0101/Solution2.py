# Source : https://leetcode.com/problems/symmetric-tree/
# Author : penpenps
# Time   : 2019-07-09

# Recursively check whether the child node is symmetric or not
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
        # Check whether left and right child are symmetic
        def symmetricEqual(left, right):
            # left and right child are both None, return True
            if not left and not right: return True
            # one of left and right is None, return False
            if not left or not right: return False
            # the value of left and right are not equal, return False
            if left.val != right.val:
                return False
            return symmetricEqual(left.left, right.right) and symmetricEqual(left.right, right.left)
        
        if not root:
            return True

        return symmetricEqual(root.left, root.right)