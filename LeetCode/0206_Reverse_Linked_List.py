# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head == None:
            return None
        
        if head.next != None:
            result = Solution.reverseList(self, head.next)
            head.next.next = head
        else:
            return head
        
        head.next = None
        return result
    
