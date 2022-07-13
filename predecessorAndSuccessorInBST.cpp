/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

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

        ~BinaryTreeNode() {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

*************************************************************/
// T.C. = O(H)where H = log N
// S.C. = O(1)
int predecessorInBST(BinaryTreeNode<int>* root, int key){
    if(root == NULL)return -1;
    int ans = -1;
    while(root){
        if(root->data < key){
            ans = root->data;
            root = root->right;
        }
        else{
            root = root->left;
        }
    }
    return ans;
}

int successorInBST(BinaryTreeNode<int>* root, int key){
    if(root == NULL)return -1;
    int ans = -1;
    while(root){
        if(root->data > key){
            ans = root->data;
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
    return ans;
}

pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    int predecessor = predecessorInBST(root, key);
    int successor = successorInBST(root, key);
    return {predecessor, successor};
    // Write your code here.
}
