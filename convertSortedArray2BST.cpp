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
TreeNode<int>*BST(vector<int> &arr, int l , int h){
    if(l > h)return NULL;
    int mid = (l + h)/2;
    TreeNode<int>*root = new TreeNode<int>(arr[mid]);
    root->left = BST(arr, l, mid - 1);
    root->right = BST(arr, mid + 1, h);
    return root;
}
TreeNode<int>* sortedArrToBST(vector<int> &arr, int n)
{
    return BST(arr, 0, n - 1);
    // Write your code here.
}