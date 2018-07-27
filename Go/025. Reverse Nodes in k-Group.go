package main

type ListNode struct {
    Val int
    Next *ListNode
}

func reverseKGroup(head *ListNode, k int) *ListNode {
	res := &ListNode{Next:head}
	first := res
	for true {
		i, last := 0, first
		for ; i < k && last != nil; i++ {
			last = last.Next
		}
		if last == nil {
			break
		}
		last = first.Next
		for i = 1; i < k; i++ {
			tmp := last.Next
			last.Next = last.Next.Next
			tmp.Next = first.Next
			first.Next = tmp
		}
		first = last
	}
	return res.Next
}