/// Source : https://leetcode.com/problems/binary-tree-paths/description/
/// Author : liuyubobobo
/// Time   : 2017-11-17

import java.util.List;
import java.util.ArrayList;
import java.util.Stack;
import javafx.util.Pair;

/// Non-Recursive
/// Using Stack
///
/// Time Complexity: O(n), where n is the node's number in the tree
/// Space Complexity: O(h), where h is the height of the tree
public class Solution2 {

    public List<String> binaryTreePaths(TreeNode root) {

        List<String> res = new ArrayList<String>();
        if(root == null)
            return res;

        Stack<Pair<TreeNode, String>> stack = new Stack<>();
        stack.push(new Pair(root, Integer.toString(root.val)));
        while(!stack.empty()){
            TreeNode cur = stack.peek().getKey();
            String s = stack.peek().getValue();
            stack.pop();

            if(cur.left == null && cur.right == null)
                res.add(s);

            if(cur.left != null)
                stack.push(new Pair<>(cur.left, s + "->" + Integer.toString(cur.left.val)));
            if(cur.right != null)
                stack.push(new Pair<>(cur.right, s + "->" + Integer.toString(cur.right.val)));
        }
        return res;
    }
}
