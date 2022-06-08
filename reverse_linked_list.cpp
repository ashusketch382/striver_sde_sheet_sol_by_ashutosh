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

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    if(head == NULL)return NULL;
    LinkedListNode<int> *prev = NULL;
    while(head){
        LinkedListNode<int> *next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
    // Write your code here
}