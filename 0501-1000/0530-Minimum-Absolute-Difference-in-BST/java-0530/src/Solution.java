/// Source : https://leetcode.com/problems/minimum-absolute-difference-in-bst/description/
/// Author : liuyubobobo
/// Time   : 2018-04-30

import java.util.ArrayList;
import java.util.Collections;

/// Traverse all nodes in BST and sort
///
/// Time Complexity: O(nlogn)
/// Space Complexity: O(n)
class Solution {

    public int getMinimumDifference(TreeNode root) {

        ArrayList<Integer> list = new ArrayList<>();
        preOrder(root, list);

        Collections.sort(list);
        int res = Integer.MAX_VALUE;
        for(int i = 1 ; i < list.size() ; i ++)
            res = Math.min(res, list.get(i) - list.get(i - 1));
        return res;
    }

    private void preOrder(TreeNode node, ArrayList<Integer> list){

        if(node == null)
            return;

        list.add(node.val);
        preOrder(node.left, list);
        preOrder(node.right, list);
    }
}
