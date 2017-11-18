/// Source : https://leetcode.com/problems/maximum-depth-of-binary-tree/description/
/// Author : liuyubobobo
/// Time   : 2017-11-17
///
/// Recursive
/// Time Complexity: O(n), where n is the nodes' number in the tree
/// Space Complexity: O(h), where h is the height of the tree
class Solution1 {

    // Definition for a binary tree node.
    public class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode(int x) { val = x; }
    }

    public int maxDepth(TreeNode root) {

        if(root == null)
            return 0;

        return 1 + Math.max(maxDepth(root.left), maxDepth(root.right));
    }
}
