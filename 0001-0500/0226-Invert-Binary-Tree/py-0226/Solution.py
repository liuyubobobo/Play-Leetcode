# Source : https://leetcode.com/problems/invert-binary-tree/
# Author : penpenps
# Time   : 2019-08-01

# Recursive 
# Time Complexity: O(n), the number of tree's nodes
# Space Complexity: O(h), the height of tree

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def invertTree(self, root: TreeNode) -> TreeNode:
        if not root: return root
        if root.left:
            root.left = self.invertTree(root.left)
        if root.right:
            root.right = self.invertTree(root.right)
        if root.left or root.right:
            root.left, root.right = root.right, root.left
        return root