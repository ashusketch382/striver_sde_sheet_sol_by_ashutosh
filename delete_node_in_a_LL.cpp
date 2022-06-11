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

void deleteNode(LinkedListNode<int> * node) {
    // Write your code here.
    if(node == NULL)return;
    if(node->next != NULL){
        node->data = node->next->data;
        node->next = node->next->next;
        return;
    }
    LinkedListNode<int>* curr = node;
    while(curr->next != node){
        curr = curr->next;
    }
    curr->next = curr->next->next;
}