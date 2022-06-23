/************************************************************

    Following is the Binary Tree node structure:
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };


************************************************************/
#include<bits/stdc++.h>
bool isLeaf(TreeNode<int> *root){
    if(root == NULL)return 0;
    if(root->left == NULL && root->right == NULL)return 1;
    return 0;
}
void leftBoundary(TreeNode<int> *root, vector<int> &res){
    if(root == NULL)return ;
    while(root){
        if(!isLeaf(root))
            res.push_back(root->data);
        if(root->left == NULL)root = root->right;
        else root = root->left;
    }
}

void rightBoundary(TreeNode<int>*root, vector<int>&res){
    if(root == NULL)return ;
    vector<int>temp;
    while(root){
        if(!isLeaf(root))temp.push_back(root->data);
        if(root->right == NULL)root = root->left;
        else root = root->right;
    }
    for(int i = temp.size() - 1; i >= 0; --i){
        res.push_back(temp[i]);
    }
    
}
void leafs(TreeNode<int>*root, vector<int> &res){
    if(root == NULL)return ;
    
    if(isLeaf(root))res.push_back(root->data);
    leafs(root->left, res);
    leafs(root->right, res);
}
vector<int> traverseBoundary(TreeNode<int>* root){
    // Write your code here.
    vector<int>res;
    if(root == NULL)return res;
    if(!isLeaf(root))
        res.push_back(root->data);

    leftBoundary(root->left, res);    
        
    leafs(root, res);

    rightBoundary(root->right, res); 

    return res;
}