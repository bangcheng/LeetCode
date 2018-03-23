// Linked List Cycle
// Given a linked list, determine if it has a cycle in it.

// Follow up:
// Can you solve it without using extra space?
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
// 设置快慢指针，快指针每次移动两个，慢指针每次移动一个
// 如果链表有环，那么一定会相遇  
// 
bool hasCycle(struct ListNode *head) {
	struct ListNode *fast=head;
	struct ListNode *slow=head;
	while(slow!=NULL && fast!=NULL && fast->next!=NULL)
	{
		fast=fast->next;
		fast=fast->next;
		slow=slow->next;
		if(fast==slow) return 1;
	}
	return 0;
}

bool hasCycle(struct ListNode *head) {
	if(head==NULL||head->next==NULL)
		return 0;
	struct ListNode *fast=head;
	struct ListNode *slow=head;
	while(1)
	{
		fast=fast->next;
		if(fast==NULL) return 0;
		fast=fast->next;
		if(fast==NULL) return 0;
		slow=slow->next;
		if(fast==slow) return 1;
	}
}