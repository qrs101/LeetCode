class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        p1 = head
        p2 = head
        i = 0
        while i < n and p2 is not None:
            p2 = p2.next
            i += 1
        if p2 is None:
            return head.next
        while p2.next is not None:
            p1 = p1.next
            p2 = p2.next
        p1.next = p1.next.next
        return head
