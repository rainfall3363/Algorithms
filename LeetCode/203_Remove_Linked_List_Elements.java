/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode removeElements(ListNode head, int val) {
        while (head != null) {
            if (head.val == val) {
                head = head.next;
            }
            else {
                break;
            }
        }
        
        ListNode iter = head;
        while (iter != null) {
            if (iter.next != null && iter.next.val == val) {
                iter.next = iter.next.next;
            }
            else {
                iter = iter.next;
            }
        }
      
        return head;
    }
}
