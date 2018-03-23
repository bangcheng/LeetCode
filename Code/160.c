Intersection of Two Linked Lists
Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3
begin to intersect at node c1.


Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
// 因为如果两个链长度相同的话，那么对应的一个个比下去就能找到，所以只需要把长链表变短即可。
// 具体算法为：分别遍历两个链表，得到分别对应的长度。然后求长度的差值，把较长的那个链表向后移动这个差值的个数，
// 然后一一比较即可

// 链表这一问题注意利用距离相等 这个方法
// 求最后一个元素的前i的元素    
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    int numA=0,numB=0;
    struct ListNode *A=headA,*B=headB;
    while(A!=NULL)
    {
    	numA++;
    	A=A->next;
    }
    while(B!=NULL)
    {
    	numB++;
    	B=B->next;
    }
    A=headA,B=headB;
    if(numA>numB)
    	for (int i = 0; i < numA-numB; ++i)  A=A->next;
    if(numA<numB)
    	for (int i = 0; i < numB-numA; ++i)  B=B->next;
  	while(A!=NULL&&B!=NULL)
  	{
  		if(A==B) return A;
  		A=A->next;
  		B=B->next;
  	}
  	return 0;
}