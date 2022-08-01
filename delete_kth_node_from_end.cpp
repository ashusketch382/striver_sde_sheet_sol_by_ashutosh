/*
Time Complexity
O(N), where ‘N’ is the number of nodes in the linked list.

 

In the worst case, we will be traversing the whole linked list. Hence, the overall complexity is O(N).

Space Complexity
O(1).

 

In the worst case, only a constant extra space is required.

*/
#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

LinkedListNode<int>* removeKthNode(LinkedListNode<int> *head, int K)
{
    if(K == 0)return head;
    if(head == NULL) return NULL;
    LinkedListNode<int> *start = new LinkedListNode<int>(0);
    start->next = head;
    LinkedListNode<int>* fast = start;
    LinkedListNode<int>* slow = start;
    
    for(int i = 1; i <= K ; i++){
        fast = fast->next;
    }
    while(fast->next != NULL){
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = slow->next->next;
    return start->next;
    // Write your code here.
}