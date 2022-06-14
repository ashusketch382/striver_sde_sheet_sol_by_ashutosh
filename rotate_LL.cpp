#include <bits/stdc++.h> 
/********************************

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

********************************/


Node *rotate(Node *head, int k){
    if(head == NULL || k == 0)return head;
    int size = 1;
    Node *curr = head;
    
    while(curr->next){
        curr = curr->next;
        size++;
    }
    curr->next = head;
    k = k % size;
    k = size - k;
    while(k--){
        curr = curr->next;
    }
    head = curr->next;
    curr->next = NULL;
    return head;
     // Write your code here.
}