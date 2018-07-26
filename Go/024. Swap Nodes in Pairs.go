package main

type ListNode struct {
    Val int
    Next *ListNode
}

func swapPairs(head *ListNode) *ListNode {
	res := &ListNode{Next:head}
	p := res
	for p.Next != nil && p.Next.Next != nil {
		tmp := p.Next
		p.Next = p.Next.Next
		tmp.Next = p.Next.Next
		p.Next.Next = tmp
		p = p.Next.Next
	}
	return res.Next
}