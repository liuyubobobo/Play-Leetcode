/// Source : https://leetcode.com/problems/invert-binary-tree/description/
/// Author : liuyubobobo
/// Time   : 2017-11-17

import java.util.LinkedList;

/// Non-Recursive
/// Time Complexity: O(n), where n is the node's number of the tree
/// Space Complexity: O(h), where h is the height of the tree
public class Solution2 {

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

        LinkedList<TreeNode> queue = new LinkedList<TreeNode>();
        queue.addLast(root);
        while(!queue.isEmpty()){
            TreeNode curNode = queue.removeFirst();

            TreeNode tempNode = curNode.left;
            curNode.left = curNode.right;
            curNode.right = tempNode;

            if(curNode.left != null)
                queue.addLast(curNode.left);
            if(curNode.right != null)
                queue.push(curNode.right);
        }

        return root;
    }
}
