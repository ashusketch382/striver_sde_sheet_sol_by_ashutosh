/************************************************************

    Following is the Binary Tree node structure:

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


************************************************************/
void inorder(BinaryTreeNode<int> *root, vector<int>& temp){
    if(root == NULL)return ;
    inorder(root->left, temp);
    temp.push_back(root->data);
    inorder(root->right, temp);
}
void preorder(BinaryTreeNode<int> *root, vector<int>& temp){
    if(root == NULL)return ;
    temp.push_back(root->data);
    preorder(root->left, temp);
    preorder(root->right, temp);
}
void postorder(BinaryTreeNode<int> *root, vector<int> &temp){
    if(root == NULL)return ;
    postorder(root->left, temp);
    postorder(root->right, temp);
    temp.push_back(root->data);
}
vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    // Write your code here.
    vector<vector<int>>res;
    vector<int>temp;
    inorder(root, temp);
    res.push_back(temp);
    temp.clear();
    preorder(root, temp);
    res.push_back(temp);
    temp.clear();
    postorder(root, temp);
    res.push_back(temp);
    return res;
}