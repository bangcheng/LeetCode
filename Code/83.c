/*
83. Remove Duplicates from Sorted List

Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
// 基本思路和删除数组一样
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode *p=head;
    struct ListNode *p1;
    struct ListNode *q=head;     //存放新链表的最后一个指针
    int num=p->val;
    while(p!=NULL)
    {
    	if(p->val!=num)
    	{
    		q->next=p;
    		q=p;
    		num=p->val;
    		p=p->next;
    	}
    	else
    	{
    		p1=p;
    		p=p->next;
    		free(p1);   //删除
    	}
    }
    q->next=NULL;
    return head;
}

typedef struct ListNode ListNode;
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (head == NULL) {
        return head;
    }
    ListNode *prev = head, *cur = head->next;
    while (cur != NULL) {
        if (prev->val == cur->val) {
            prev->next = cur->next;
            free(cur);
        } else {
            prev = cur;
        }
        cur = prev->next;
    }
    return head;
}