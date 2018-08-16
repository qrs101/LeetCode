package main

type ListNode struct {
    Val int
    Next *ListNode
}

func rotateRight(head *ListNode, k int) *ListNode {
	if head == nil || k == 0 {
		return head
	}
	var p, q *ListNode
	var n int
	for p, n = head, 0; p != nil; p, n = p.Next, n + 1 {}
	k = k % n
	res := &ListNode{0, head}
	p, q = res, res
	for i := 0; i < k; i, q = i + 1, q.Next {}
	for ; q.Next != nil; p, q = p.Next, q.Next {}
	q.Next = res.Next
	res.Next = p.Next
	p.Next = nil
	return res.Next
}