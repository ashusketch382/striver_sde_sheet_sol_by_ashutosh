#include <bits/stdc++.h> 
/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    if(first == NULL)return second;
    if(second == NULL)return first;
    
    Node<int>*res_head;
    if(first->data <= second->data){
        res_head = first;
        first = first->next;
    }
    else{
        res_head = second;
        second = second->next;
    }
    Node<int>*temp = res_head;
    while(first != NULL && second != NULL){
        if(first->data <= second->data){
            temp->next = first;
            temp = temp->next;
            first = first->next;
        }
        else{
            temp->next = second;
            temp = temp->next;
            second = second->next;
        }
    }
    if(first != NULL)temp->next = first;
    if(second != NULL)temp->next = second;
    return res_head;
    // Write your code here.
}
