/// Source : https://leetcode.com/problems/minimum-absolute-difference-in-bst/description/
/// Author : liuyubobobo
/// Time   : 2018-04-30

import java.util.ArrayList;
import java.util.Collections;

/// Using inorder to traverse all nodes
/// and calculates the result during the inorder traverse
///
/// Time Complexity: O(n)
/// Space Complexity: O(logn)
class Solution3 {

    private Integer prev = null;

    public int getMinimumDifference(TreeNode root) {

        prev = null;
        return inOrder(root);
    }

    private int inOrder(TreeNode node){

        if(node == null)
            return Integer.MAX_VALUE;

        int res = Integer.MAX_VALUE;

        res = Math.min(res, inOrder(node.left));

        if(prev != null)
            res = Math.min(res, node.val - prev);
        prev = node.val;

        res = Math.min(res, inOrder(node.right));

        return res;
    }
}
