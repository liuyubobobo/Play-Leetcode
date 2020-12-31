/// Source : https://leetcode.com/problems/validate-binary-search-tree/description/
/// Author : liuyubobobo
/// Time   : 2018-05-22

/// Using inOrder traverse
/// Find the mistaked swapped nodes during the traversing
///
/// Time Complexity: O(n)
/// Space Complexity: O(h)
class Solution2 {

    private TreeNode pre;
    private TreeNode a, b;

    public void recoverTree(TreeNode root) {

        pre = null;
        a = null;
        b = null;
        inOrder(root);

        int t = a.val;
        a.val = b.val;
        b.val = t;
    }

    private void inOrder(TreeNode node){

        if(node == null)
            return;

        inOrder(node.left);

        if(pre != null && pre.val > node.val){
            if (a == null){
                a = pre;
                b = node;
            }
            else
                b = node;
        }
        pre = node;

        inOrder(node.right);
    }
}