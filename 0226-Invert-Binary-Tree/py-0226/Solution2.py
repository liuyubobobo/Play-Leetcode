# Source : https://leetcode.com/problems/invert-binary-tree/
# Author : penpenps
# Time   : 2019-08-01

# BFS, iterative 
# Time Complexity: O(n), the number of tree's nodes
# Space Complexity: O(n), the max node number by level

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def invertTree(self, root: TreeNode) -> TreeNode:
        if not root: return root
        queue = [root]
        while queue:
            node = queue.pop(0)
            node.left, node.right = node.right, node.left
            if node.left:
                queue.append(node.left)
            if node.right:
                queue.append(node.right)
        return root
    