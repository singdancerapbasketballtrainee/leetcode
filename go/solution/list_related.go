package solution

//反转链表

type ListNode struct {
	Val  int
	Next *ListNode
}

//反转链表
func reverseList(head *ListNode) *ListNode {
	var cur *ListNode
	pre := head
	for pre != nil {
		tmp := pre.Next
		pre.Next = cur
		cur = pre
		pre = tmp
	}
	return cur
}

//删除链表的倒数第 N 个结点
func removeNthFromEnd(head *ListNode, n int) *ListNode {
	reList := reverseList(head)
	if n == 1 {
		return reverseList(reList.Next)
	}
	cur := reList
	for i := 0; i < n-2; i++ {
		cur = cur.Next
	}
	cur.Next = cur.Next.Next
	return reverseList(head)
}

//合并两个有序链表
func mergeTwoLists(list1 *ListNode, list2 *ListNode) *ListNode {
	if list1 == nil {
		return list2
	}
	if list2 == nil {
		return list1
	}
	var cur *ListNode
	if list1.Val <= list2.Val {
		cur = list1
		list1 = list1.Next
	} else {
		cur = list2
		list2 = list2.Next
	}
	retList := cur
	for list1 != nil || list2 != nil {
		if list1 == nil {
			cur.Next = list2
			break
		}
		if list2 == nil {
			cur.Next = list1
			break
		}
		if list1.Val <= list2.Val {
			cur.Next = list1
			list1 = list1.Next
		} else {
			cur.Next = list2
			list2 = list2.Next
		}
		cur = cur.Next
	}
	return retList
}
