/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
#include<bits/stdc++.h>
BinaryTreeNode<int>* BTtoDLL(BinaryTreeNode<int>* root){
    // Write your code here
    BinaryTreeNode<int>* head = NULL;
    BinaryTreeNode<int>* pre = NULL;
    stack<BinaryTreeNode<int>* >s;
    while(root || !s.empty()){
        if(root == NULL){
            root = s.top();
            
            root->left = pre;
            if(pre == NULL){
                head = root;
            }
            else{
                pre->right = root;
            }
            pre = root;
            
            root = root->right;
            s.pop();
        }
        else{
            s.push(root);
            root = root->left;
        }
    }
    return head;
}