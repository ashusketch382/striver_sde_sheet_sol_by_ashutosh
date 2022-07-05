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
T.C. = O(N)
S.C. = O(N)//recursion call stack
************************************************************/
void get_k_th_smallest(TreeNode<int> *root, int &k, int &ans){
    if(root == NULL)return ;
    get_k_th_smallest(root->left, k, ans);
    if(--k == 0)ans =root->data;
    get_k_th_smallest(root->right, k , ans);
}
int kthSmallest(TreeNode<int> *root, int k)
{
    int ans = -1e9;
    get_k_th_smallest(root, k, ans);
    return ans;
	//	Write the code here.
}