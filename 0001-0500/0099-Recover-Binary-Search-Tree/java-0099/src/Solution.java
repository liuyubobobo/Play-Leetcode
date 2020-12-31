/// Source : https://leetcode.com/problems/validate-binary-search-tree/description/
/// Author : liuyubobobo
/// Time   : 2018-05-22

import java.util.ArrayList;

/// Using inOrder traverse
/// Store all Nodes in an ArrayList and find the mistaked swapped nodes
///
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {

    public void recoverTree(TreeNode root) {

        ArrayList<TreeNode> list = new ArrayList<>();
        inOrder(root, list);

        TreeNode a = null;
        TreeNode b = null;
        for(int i = 1 ; i < list.size() ; i ++) {
            if (list.get(i - 1).val > list.get(i).val) {
                if (a == null){
                    a = list.get(i - 1);
                    b = list.get(i);
                }
                else {
                    b = list.get(i);
                    break;
                }
            }
        }

        int t = a.val;
        a.val = b.val;
        b.val = t;
    }

    private void inOrder(TreeNode node, ArrayList<TreeNode> list){

        if(node == null)
            return;

        inOrder(node.left, list);
        list.add(node);
        inOrder(node.right, list);
    }

    public static void main(String[] args){

        TreeNode root = new TreeNode(3);
        root.left = new TreeNode(1);
        root.right = new TreeNode(4);
        root.right.left = new TreeNode(2);

        (new Solution()).recoverTree(root);
    }
}