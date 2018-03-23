/*21. Merge Two Sorted Lists
Merge two sorted linked lists and return it as a new list. 
The new list should be made by splicing together the nodes of the first two lists.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {\
	if(l1==NULL)
		return l2;
	if(l2==NULL)
		return l1;
    struct ListNode *p1;
    struct ListNode *p2;
    struct ListNode *root=l1;
    struct ListNode *p3;
    if (l1->val>l2->val)
    {
    	p1=l1;
    	p2=l2->next;
    	root=l2;
    	p3=l2;
    }
    else
    {
    	p1=l1->next;
    	p3=l1;
    	p2=l2;
    }
    while(p1!=NULL&&p2!=NULL)
    {
    	if (p1->val>p2->val)
    	{
    		p3->next=p2;
    		p3=p2;
    		p2=p2->next;
    	}
    	else
    	{
    		p3->next=p1;
    		p3=p1;
    		p1=p1->next;
    	}
    }
    if(p1==NULL)
    	p3->next=p2;
    else
    	p3->next=p1;
    return root;
}





// 优
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) 
{
    struct ListNode *resultHead = NULL;
    struct ListNode *resultTail = NULL;
    struct ListNode *currentNode;
    
    if (l1 == NULL)
        return l2;
    else if (l2 == NULL)
        return l1;
    
    while(l1 && l2)
    {
        if (l1->val > l2->val)
        {
            currentNode = l2;
            l2 = l2->next;
        }
        else
        {
            currentNode = l1;
            l1 = l1->next;
        }
        
        currentNode->next = NULL;
        
        if (resultHead == NULL)
        {
            resultHead = currentNode;
            resultTail = currentNode;
        }
        else
        {
            resultTail->next = currentNode;
            resultTail = currentNode;
        }
    }
    
    if (l1)
        resultTail->next = l1;
    else if (l2)
        resultTail->next = l2;
    
    return resultHead;
}