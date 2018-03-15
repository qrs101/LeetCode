# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        carry = 0
        ans = ListNode(0)
        l = ans
        while l1 is not None and l2 is not None:
            num = l1.val + l2.val + carry
            carry = num // 10
            num = num % 10
            l.next = ListNode(num)
            l = l.next
            l1 = l1.next
            l2 = l2.next
        if l1 is None:
            p = l2
        else:
            p = l1
        while p is not None:
            num = p.val + carry
            carry = num // 10
            num = num % 10
            l.next = ListNode(num)
            l = l.next
            p = p.next
        if carry != 0:
            l.next = ListNode(carry)
        return ans.next
