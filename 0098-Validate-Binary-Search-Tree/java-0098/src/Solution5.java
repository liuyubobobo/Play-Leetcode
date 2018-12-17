/// Source : https://leetcode.com/problems/validate-binary-search-tree/description/
/// Author : liuyubobobo
/// Time   : 2018-12-16

/// Morris InOrder traversal
/// Attention: you can not change the give Tree structure in Leetcode,
/// So try to return result early will lead to RE :-)
///
/// Time Complexity: O(n)
/// Space Complexity: O(1)
public class Solution5 {

    private boolean flag;
    private int pre;

    public boolean isValidBST(TreeNode root) {

        flag = false;
        pre = -1;

        TreeNode cur = root;
        boolean res = true;
        while(cur != null){

            if(cur.left == null){
                if(!process(cur.val)) return false;
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
                    if(!process(cur.val))
                        return false;
                    cur = cur.right;
                }
            }
        }
        return true;
    }

    private boolean process(int v){

        if(flag && pre >= v)
            return false;

        flag = true;
        pre = v;
        return true;
    }
}
