/// Source : https://leetcode.com/problems/validate-binary-search-tree/description/
/// Author : liuyubobobo
/// Time   : 2018-05-29

/// Using Morris inOrder traversal
/// Find the mistaked swapped nodes during the traversing
///
/// Time Complexity: O(n)
/// Space Complexity: O(1)
class Solution3 {

    private TreeNode pre;
    private TreeNode a, b;

    public void recoverTree(TreeNode root) {

        TreeNode cur = root;
        while(cur != null){
            if(cur.left == null){
                process(cur);
                cur = cur.right;
            }
            else{
                TreeNode prev = cur.left;
                while(prev.right != null && prev.right != cur)
                    prev = prev.right;

                if(prev.right == null){
                    prev.right = cur;
                    cur = cur.left;
                }
                else{
                    prev.right = null;
                    process(cur);
                    cur = cur.right;
                }
            }
        }

        int t = a.val;
        a.val = b.val;
        b.val = t;
    }

    private void process(TreeNode node){

        if(pre != null && pre.val > node.val){
            if(a == null){
                a = pre;
                b = node;
            }
            else
                b = node;
        }

        pre = node;
    }
}