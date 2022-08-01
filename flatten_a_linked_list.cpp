/*
Time Complexity
O(N * K), where ‘N’ denotes the size of the linked list and ‘K’ is the average number of child nodes for each of the N nodes. 

 

Since, every next-node and every child node in the linkedlist is traversed only once, the final complexity would be O(N * K).

Space Complexity
O(N), where ‘N’ denotes the size of the linked list.

 

Since for every call on a horizontal node each child sublist is called so the stack in recursion will always at most have N stacks .


*/
#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the Node class:

class Node {
public:
    int data;
    Node* next;
    Node* child;

    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->child = NULL;
    }
};

*****************************************************************/
struct comp{
    bool operator()(Node *a, Node* b){
        return a->data > b->data;
    }
};
Node* flattenLinkedList(Node* head) 
{
    if(head == NULL || head->next == NULL)return head;
    Node *root = new Node(-1);
    Node *temp = root;
    
    priority_queue<Node*, vector<Node*>, comp>pq;
    while(head){
        pq.push(head);
        head = head->next;
    }
    while(!pq.empty()){
        Node *head = pq.top();
        temp->child = head;
        temp = head;
        pq.pop();
        if(head->child)pq.push(head->child);
    }
    return root->child;
    // Write your code here
}