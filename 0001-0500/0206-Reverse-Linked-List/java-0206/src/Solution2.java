/// Source : https://leetcode.com/problems/reverse-linked-list/description/
/// Author : liuyubobobo
/// Time   : 2017-11-15

/// Recursive
/// Time Complexity: O(n)
/// Space Complexity: O(n)
public class Solution2 {

    // Definition for singly-linked list.
    public class ListNode {
        int val;
        ListNode next;
        ListNode(int x) { val = x; }
    }

    public ListNode reverseList(ListNode head) {

        // 递归终止条件
        if(head == null|| head.next == null)
            return head;

        ListNode rhead = reverseList(head.next);

        // head->next此刻指向head后面的链表的尾节点
        // head->next->next = head把head节点放在了尾部
        head.next.next = head;
        head.next = null;

        return rhead;
    }
}
