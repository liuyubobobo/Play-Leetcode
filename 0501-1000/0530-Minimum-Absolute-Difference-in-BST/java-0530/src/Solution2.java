/// Source : https://leetcode.com/problems/minimum-absolute-difference-in-bst/description/
/// Author : liuyubobobo
/// Time   : 2018-04-30

import java.util.ArrayList;
import java.util.Collections;

/// Using inorder to traverse all nodes
///
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution2 {

    public int getMinimumDifference(TreeNode root) {

        ArrayList<Integer> list = new ArrayList<>();
        inOrder(root, list);

        int res = Integer.MAX_VALUE;
        for(int i = 1 ; i < list.size() ; i ++)
            res = Math.min(res, list.get(i) - list.get(i - 1));
        return res;
    }

    private void inOrder(TreeNode node, ArrayList<Integer> list){

        if(node == null)
            return;

        inOrder(node.left, list);
        list.add(node.val);
        inOrder(node.right, list);
    }
}
