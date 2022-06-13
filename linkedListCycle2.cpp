#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
            int data;
            Node *next;
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
        };

*****************************************************************/

Node *firstNode(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    Node *entry = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(fast == slow){
            while(fast != entry){
                fast = fast->next;
                entry = entry->next;
            }
            return fast;
        }
    }
    return NULL;
    //    Write your code here.
}