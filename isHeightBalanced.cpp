/*
    Time complexity: O(N^2)
    Space complexity: O(N)
    
    Where 'N' is number of nodes in binary tree.
*/

int height(BinaryTreeNode<int>* root) {
    
    // Base condition.
    if (!root) {
        return 0;
    }

    return max(height(root->left), height(root->right)) + 1;
}

bool isBalancedBT(BinaryTreeNode<int>* root) {

    // Base condition.
    if (!root) {
        return true;
    }

    // Height of left and right child subtree.
    int heightLeft = height(root->left);
    int heightRight = height(root->right);

    // Allowed only height difference '0, 1, -1' and both subtrees balanced.
    if (isBalancedBT(
            root->left) == true &&
        isBalancedBT(root->right) == true && abs(heightLeft - heightRight) <= 1) {
        return true;
    }

    // If current subtree is not balanced.
    return false;
}




/*
    Time complexity: O(N)
    Space complexity: O(N)
    
    Where 'N' is number of nodes in binary tree.
*/

int helperMethod(BinaryTreeNode<int>* root){

    // Base case.
    if(!root){
        return 0;
    }

    int leftValue = helperMethod(root->left);
    int rightValue = helperMethod(root->right);

    // If one of them is '-1' then child subtree are not balanced.
    if(leftValue == -1 or rightValue == -1){
        return -1;
    }

    // Allow only '0, -1, 1' height differencein 'left' child subtree height and 'right' subtree height.
    if(abs(leftValue-rightValue) <= 1){
        return max(leftValue, rightValue)+1;
    }

    // If left and right child subtree height more than '2'.
    return -1;
}

bool isBalancedBT(BinaryTreeNode<int>* root){

    // Base condition.
    if(!root){
        return true;
    }

    // If root tree is balanced.
    if (helperMethod(root) != -1){
        return true;
    }
    else{
        return false;
    }
}





//my sol
//T.C. = O(n)
//S.C. = O(n)
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
int checkBalancedBT(BinaryTreeNode<int>* root, bool & isBalanced){
    if(root == NULL)return 0;
    int left = checkBalancedBT(root->left, isBalanced);
    int right = checkBalancedBT(root->right, isBalanced);
    if(abs(left - right) > 1)isBalanced = false;
    return max(left, right) + 1;
}

bool isBalancedBT(BinaryTreeNode<int>* root) {
    // Write your code here.
    bool isBalanced = true;
    checkBalancedBT(root, isBalanced);
    return isBalanced;
}