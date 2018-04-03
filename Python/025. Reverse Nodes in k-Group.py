class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def reverseKGroup(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        ans = ListNode(1)
        ans.next = head
        T = ans
        q = ans
        while True:
            i = 0
            while i < k and q is not None:
                q = q.next
                i += 1
            if q is None:
                break
            p = T.next
            tmp = p
            for j in range(k - 1):
                T.next = p.next
                p.next = q.next
                q.next = p
                p = T.next
            T = tmp
            q = tmp
        return ans.next