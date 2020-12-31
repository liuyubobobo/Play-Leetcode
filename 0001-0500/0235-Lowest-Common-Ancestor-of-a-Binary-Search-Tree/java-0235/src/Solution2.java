/// Source : https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/
/// Author : liuyubobobo
/// Time   : 2018-12-16

/// Non-Recursive
/// Time Complexity: O(lgn), where n is the node's number of the tree
/// Space Complexity: O(1)
class Solution2 {

    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {

        if(root == null)
            return root;

        TreeNode cur = root;
        while(cur != null){
            if(p.val < cur.val && q.val < cur.val)
                cur = cur.left;
            else if(p.val > cur.val && q.val > cur.val)
                cur = cur.right;
            else
                return cur;
        }
        return  null;
    }
}
