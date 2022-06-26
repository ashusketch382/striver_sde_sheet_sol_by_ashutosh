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
LinkedListNode<int> *reverse(LinkedListNode<int> *root){
    if(root == NULL) return NULL;
    LinkedListNode<int> *prev = NULL;
    while(root){
        LinkedListNode<int> *next = root->next;
        root->next = prev;
        prev = root;
        root = next;
    }
    return prev;
}
bool isPalindrome(LinkedListNode<int> *head) {
    // Write your code here.
    LinkedListNode<int> *slow = new LinkedListNode<int>(-1);
    slow->next = head;
    LinkedListNode<int> *fast = new LinkedListNode<int>(-1);
    fast->next = head;
    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    slow->next = reverse(slow->next);
    LinkedListNode<int> *curr = head;
    slow = slow->next;
    while(slow != NULL){
        if(slow->data != curr->data)return 0;
        slow = slow->next;
        curr = curr->next;
    }
    return 1;

}