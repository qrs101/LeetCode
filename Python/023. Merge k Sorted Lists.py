class Solution:
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        if len(lists) == 0:
            return None
        while len(lists) > 1:
            l = self.mergeTwoLists(lists[0], lists[1])
            lists.append(l)
            lists = lists[2 :]

        return lists[0]

    def mergeTwoLists(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        if l1 is None:
            return l2
        if l2 is None:
            return l1
        p1 = l2
        p2 = l1
        if l1.val <= l2.val:
            p1 = l1
            p2 = l2
        ans = p1
        while p1 is not None and p2 is not None:
            if p1.next is None:
                p1.next = p2
                break
            if p1.next.val <= p2.val:
                p1 = p1.next
            else:
                tmp = p2.next
                p2.next = p1.next
                p1.next = p2
                p1 = p2
                p2 = tmp

        return ans