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
int diameter(TreeNode<int>*root, int &width){
    if(root == NULL)return 0;
    int left = diameter(root->left, width);
    int right = diameter(root->right, width);
    width = max(width, left + right + 1);
    return max(left, right) + 1;
}

int diameterOfBinaryTree(TreeNode<int> *root)
{
    if(root == NULL)return 0;
    int width = 0;
    diameter(root, width);
    return width - 1;
	// Write Your Code Here.
}
