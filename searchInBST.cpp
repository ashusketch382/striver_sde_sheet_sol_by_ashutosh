/*
    Following is the Binary Tree node structure:

    class BinaryTreeNode {
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
*/

bool searchInBST(BinaryTreeNode<int> *root, int x) {
    if(root == NULL)return false;
    if(root->data == x)return true;
    if(searchInBST(root->left, x))return true;
    if(searchInBST(root->right, x))return true;
    return false;
    // Write your code here.
}