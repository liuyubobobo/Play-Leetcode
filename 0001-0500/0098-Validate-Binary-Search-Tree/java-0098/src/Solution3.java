/// Source : https://leetcode.com/problems/validate-binary-search-tree/description/
/// Author : liuyubobobo
/// Time   : 2018-12-16


import java.util.Stack;

/// Non-Recursion Solution for Recursion thinking
/// Time Complexity: O(n)
/// Space Complexity: O(h)
public class Solution3 {


    public boolean isValidBST(TreeNode root) {

        if(root == null) return true;

        Stack<TreeNode> stack = new Stack<>();
        Stack<Integer> lower = new Stack<>();
        Stack<Integer> upper = new Stack<>();

        stack.push(root);
        lower.push(Integer.MIN_VALUE);
        upper.push(Integer.MAX_VALUE);
        while(!stack.empty()){
            TreeNode cur = stack.pop();
            int left = lower.pop();
            int right = upper.pop();

            if(cur.val < left || cur.val > right)
                return false;

            if(cur.right != null){
                if(cur.right.val <= cur.val) return false;
                stack.push(cur.right);
                lower.push(cur.val + 1);
                upper.push(right);
            }

            if(cur.left != null){
                if(cur.left.val >= cur.val) return false;
                stack.push(cur.left);
                lower.push(left);
                upper.push(cur.val - 1);
            }
        }
        return true;
    }
}
