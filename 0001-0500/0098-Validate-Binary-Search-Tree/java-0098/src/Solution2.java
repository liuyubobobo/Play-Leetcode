/// Source : https://leetcode.com/problems/validate-binary-search-tree/description/
/// Author : liuyubobobo
/// Time   : 2018-05-22

/// Recursive test
/// Time Complexity: O(n)
/// Space Complexity: O(h)
class Solution2 {

    public boolean isValidBST(TreeNode root) {

        return isValidBST(root, Integer.MIN_VALUE, Integer.MAX_VALUE);
    }

    private boolean isValidBST(TreeNode node, int min, int max){

        if(node == null)
            return true;

        if(node.val < min || node.val > max)
            return false;

        if(node.left != null && node.left.val >= node.val)
            return false;

        if(node.right != null && node.right.val <= node.val)
            return false;

        return isValidBST(node.left, min, node.val - 1) &&
                isValidBST(node.right, node.val + 1, max);
    }

    public static void main(String[] args){

        TreeNode root = new TreeNode(-2147483648);
        root.left = new TreeNode(-2147483648);

        System.out.println((new Solution2()).isValidBST(root));
    }
}
