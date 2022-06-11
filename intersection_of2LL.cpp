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

int findIntersection(Node *firstHead, Node *secondHead)
{
    Node *firstCurr = firstHead;
    Node *secondCurr = secondHead;
    
    while(firstCurr != secondCurr){
        firstCurr = firstCurr->next;
        secondCurr = secondCurr->next;
        if(firstCurr == secondCurr)return firstCurr == NULL?-1:firstCurr->data;
        if(firstCurr == NULL)firstCurr = secondHead;
        if(secondCurr == NULL)secondCurr = firstHead;
    }
    return firstCurr->data;
    //Write your code here
}