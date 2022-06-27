/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
void floor(TreeNode<int> *root, int x, int &ans){
    if(root == NULL)return ;
    if(root->val == x){
        ans = x;
        return;
    }
    
    else if(x > root->val){
        ans = root->val;
        floor(root->right, x, ans);
    }
    else{
        floor(root->left, x, ans);
    }
}
int floorInBST(TreeNode<int> * root, int X)
{
    int ans = -1;
    floor(root, X, ans);
    return ans;
    // Write your code here.
}