/// Source : https://leetcode.com/problems/validate-binary-search-tree/description/
/// Author : liuyubobobo
/// Time   : 2018-05-22

/// InOrder traverse
/// validate during the traversing
///
/// Time Complexity: O(n)
/// Space Complexity: O(h)
public class Solution4 {

    private Integer pre = null;

    public boolean isValidBST(TreeNode root) {

        return inOrder(root);
    }

    private boolean inOrder(TreeNode node){

        if(node == null)
            return true;

        if(!inOrder(node.left))
            return false;

        if(pre != null && node.val <= pre)
            return false;
        pre = node.val;

        if(!inOrder(node.right))
            return false;

        return true;
    }
}
