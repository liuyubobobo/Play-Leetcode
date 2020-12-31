/// Source : https://leetcode.com/problems/validate-binary-search-tree/description/
/// Author : liuyubobobo
/// Time   : 2018-05-22

import java.util.ArrayList;

/// Using inOrder traverse
/// Store all elements in an ArrayList
///
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {

    public boolean isValidBST(TreeNode root) {

        ArrayList<Integer> list = new ArrayList<>();
        inOrder(root, list);
        for(int i = 1 ; i < list.size() ; i ++)
            if(list.get(i - 1) >= list.get(i))
                return false;
        return true;
    }

    private void inOrder(TreeNode node, ArrayList<Integer> list){

        if(node == null)
            return;

        inOrder(node.left, list);
        list.add(node.val);
        inOrder(node.right, list);
    }
}
