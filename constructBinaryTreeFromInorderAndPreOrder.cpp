/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

#include<bits/stdc++.h>
TreeNode<int>* treeRoot(vector<int>&inorder, int inStart, int inEnd, vector<int>& preorder, int& preInd, int preSize, map<int,int>&mp){
    if(inStart > inEnd || preInd >= preSize)return NULL;
    int ind = mp[preorder[preInd++]];
    TreeNode<int>* root = new TreeNode<int>(inorder[ind]);
    root->left = treeRoot(inorder, inStart, ind - 1, preorder, preInd, preSize, mp);
    root->right = treeRoot(inorder, ind + 1, inEnd, preorder, preInd, preSize, mp);
    return root;
}
TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
    int inSize = inorder.size();
    int preSize = preorder.size();
    map<int,int>mp;
    for(int i = 0 ; i < inSize; i++)mp[inorder[i]] = i;
    int preInd = 0;
    return treeRoot(inorder, 0, inSize - 1, preorder, preInd, preSize, mp);
	//    Write your code here
}