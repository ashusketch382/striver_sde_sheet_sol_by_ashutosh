/*************************************************************
/*
    Time Complexity  : O(N)
    Space Complexity : O(N)

    Where N is the total number of nodes in the binary tree.
*/
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

vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    vector<int>res;
    if(root == NULL)return res;
    queue<BinaryTreeNode<int> *>q;
    q.push(root);
    bool reversed = false;
    while(!q.empty()){
        int size = q.size();
        vector<int>temp(size);
        for(int i = 0 ; i < size; i ++){
            BinaryTreeNode<int> *root = q.front();
            q.pop();
            int ind = reversed?(size-1-i):i;
            temp[ind] = root->data;
            if(root->left)q.push(root->left);
            if(root->right)q.push(root->right);
        }
        reversed = !reversed;
        for(int it:temp)res.push_back(it);
    }
    return res;
    // Write your code here!
}
