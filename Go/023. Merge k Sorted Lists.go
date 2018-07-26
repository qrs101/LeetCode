package main

type ListNode struct {
	Val int
	Next *ListNode
}

func mergeKLists(lists []*ListNode) *ListNode {
	if len(lists) == 0 {
		return nil
	}
	for len(lists) > 1 {
		lists = append(lists, merge2Lists(lists[0], lists[1]))
		lists = lists[2 :]
	}
	return lists[0]
}

func merge2Lists(l1 *ListNode, l2 *ListNode) *ListNode {
	res := new(ListNode)
	p := res
	for l1 != nil && l2 != nil {
		if l1.Val < l2.Val {
			p.Next = l1
			l1 = l1.Next
		} else {
			p.Next = l2
			l2 = l2.Next
		}
		p = p.Next
	}
	if l1 == nil {
		p.Next = l2
	} else {
		p.Next = l1
	}
	return res.Next
}