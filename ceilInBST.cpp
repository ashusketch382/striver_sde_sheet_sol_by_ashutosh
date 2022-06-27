/************************************************************

    Following is the TreeNode class structure:

    class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
        
        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if (left) {
              delete left;
            }
            if (right) {
              delete right;
            }
        }
    };

************************************************************/
void ceil(BinaryTreeNode<int> *root, int &ans, int x){
    if(root == NULL)return;
    if(root->data == x){
        ans = x;
        return ;
    }
    else if(root->data > x){
        ans = root->data;
        ceil(root->left, ans, x);
    }
    else{
        ceil(root->right, ans, x);
    }
}
int findCeil(BinaryTreeNode<int> *node, int x){
    // Write your code here.
    int ans = -1;
    ceil(node, ans, x);
    return ans;
}