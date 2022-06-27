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

bool partialBST(BinaryTreeNode<int> *root, int mini, int maxi){
    if(root == NULL)return 1;
    return (mini <= root->data && root->data <= maxi) && partialBST(root->left, mini, root->data) && partialBST(root->right, root->data, maxi);
}
bool validateBST(BinaryTreeNode<int> *root) {
    // Write your code here
    return partialBST(root, INT_MIN, INT_MAX);
}