/// Source : https://leetcode.com/problems/reverse-linked-list/description/
/// Author : liuyubobobo
/// Time   : 2017-11-15

/// Iterative
/// Time Complexity: O(n)
/// Space Complexity: O(1)
public class Solution1 {

    // Definition for singly-linked list.
    public class ListNode {
        int val;
        ListNode next;
        ListNode(int x) { val = x; }
    }

    public ListNode reverseList(ListNode head) {

        ListNode pre = null;
        ListNode cur = head;
        while(cur != null){
            ListNode next = cur.next;
            cur.next = pre;
            pre = cur;
            cur = next;
        }

        return pre;
    }
}
