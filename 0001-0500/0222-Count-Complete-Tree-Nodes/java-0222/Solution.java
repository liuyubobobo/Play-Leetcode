/// Source : https://leetcode.com/problems/count-complete-tree-nodes/
/// Author : Mark Zhang
/// Time   : 2020-07-09

/// Recursion
/// Time Complexity: O(n)
/// Space Complexity: O(n)

class Solution {
    public int countNodes(TreeNode root) {
        if(root == null)
            return 0;

        if(root.left == null && root.right == null)
            return 1;

        int countLeft =  countNodes(root.left);
        int countRight = countNodes(root.right);

        return countLeft + countRight + 1;
    }
}
