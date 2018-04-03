class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        ans = ListNode(1)
        ans.next = head
        p = ans
        q = ans.next
        while q is not None and q.next is not None:
            p.next = q.next
            q.next = q.next.next
            p.next.next = q
            p = q
            q = q.next
        return ans.next
