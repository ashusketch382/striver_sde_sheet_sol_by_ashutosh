/*
    ----------------- Binary Tree node class for reference -----------------

    template <typename T>
    class BinaryTreeNode {
        public : 
            T data;
            BinaryTreeNode<T> *left;
            BinaryTreeNode<T> *right;
            BinaryTreeNode<T> *next;

            BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
                next = NULL;
            }
    };
*/
#include<bits/stdc++.h>
void connectNodes(BinaryTreeNode< int > *root) {
    // Write your code here.
    queue<BinaryTreeNode<int> *>q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        BinaryTreeNode<int> *prev;
        for(int i = 0 ; i < size; i++){
            BinaryTreeNode<int> *root = q.front();
            q.pop();
            if(i == 0)prev = root;
            else{
                prev->next = root;
                prev = prev->next;
            }
            if(root->left)q.push(root->left);
            if(root->right)q.push(root->right);
        }
    }
}