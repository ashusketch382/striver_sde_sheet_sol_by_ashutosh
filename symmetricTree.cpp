/*****************************************************

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
        
        ~BinaryTreeNode() {
            if(left) 
                delete left;
            if(right) 
                delete right;
        }
    };

******************************************************/

bool symmetry(BinaryTreeNode<int> *root1, BinaryTreeNode<int>* root2){
    if(root1 == NULL || root2 == NULL)return root1 == root2;
    return (root1->data == root2->data) && symmetry(root1->left, root2->right) && symmetry(root1->right, root2->left); 
}
bool isSymmetric(BinaryTreeNode<int>* root)
{
    if(root == NULL)return 1;
    return symmetry(root->left , root->right);
    // Write your code here.    
}