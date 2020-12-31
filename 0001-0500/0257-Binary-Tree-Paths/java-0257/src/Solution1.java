/// Source : https://leetcode.com/problems/binary-tree-paths/description/
/// Author : liuyubobobo
/// Time   : 2017-11-17

import java.util.List;
import java.util.ArrayList;

/// Recursive
/// Time Complexity: O(n), where n is the node's number in the tree
/// Space Complexity: O(h), where h is the height of the tree
public class Solution1 {

    public List<String> binaryTreePaths(TreeNode root) {

        ArrayList<String> res = new ArrayList<String>();

        if(root == null)
            return res;

        if(root.left == null && root.right == null){
            res.add(Integer.toString(root.val));
            return res;
        }

        List<String> leftPaths = binaryTreePaths(root.left);
        for(String s: leftPaths){
            StringBuilder sb = new StringBuilder(Integer.toString(root.val));
            sb.append("->");
            sb.append(s);
            res.add(sb.toString());
        }

        List<String> rightPaths = binaryTreePaths(root.right);
        for(String s: rightPaths) {
            StringBuilder sb = new StringBuilder(Integer.toString(root.val));
            sb.append("->");
            sb.append(s);
            res.add(sb.toString());
        }

        return res;
    }
}
