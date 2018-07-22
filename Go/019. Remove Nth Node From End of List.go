type ListNode struct {
    Val int
    Next *ListNode
}

func removeNthFromEnd(head *ListNode, n int) *ListNode {
	res := &ListNode{0, head}
	front, rear := res, res
	var i int
	for i = 0; i < n && rear.Next != nil; i++ {
		rear = rear.Next
	}
	if i < n {
		return res.Next
	}
	for rear.Next != nil {
		front = front.Next
		rear = rear.Next
	}
	front.Next = front.Next.Next
	return res.Next
}