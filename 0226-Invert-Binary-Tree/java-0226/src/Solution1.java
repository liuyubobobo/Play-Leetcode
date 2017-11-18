/// Source : https://leetcode.com/problems/invert-binary-tree/description/
/// Author : liuyubobobo
/// Time   : 2017-11-17

/// Recursive
/// Time Complexity: O(n), where n is the node's number of the tree
/// Space Complexity: O(h), where h is the height of the tree
public class Solution1 {

    // Definition for a binary tree node.
    public class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode(int x) { val = x; }
    }

    public TreeNode invertTree(TreeNode root) {

        if(root == null)
            return null;

        TreeNode left = invertTree(root.left);
        TreeNode right = invertTree(root.right);

        root.left = right;
        root.right = left;

        return root;
    }
}
