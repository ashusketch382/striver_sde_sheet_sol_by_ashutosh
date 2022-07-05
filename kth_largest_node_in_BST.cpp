/************************************************************
    Following is the Binary Search Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
// T.C. = O(N)
// S.C. = O(N)

void getKthLargestOfBST(TreeNode<int> *root, int &k, int &ans){
    if(root == NULL)return ;
    getKthLargestOfBST(root->right, k, ans);
    if(--k == 0){
        ans = root->data;
        return ;
    }
    getKthLargestOfBST(root->left,k, ans);
}

int KthLargestNumber(TreeNode<int>* root, int k) 
{
//     int size = getSizeOfBST(root);
    int ans = -1;
//     k = size - k + 1;
    getKthLargestOfBST(root, k ,ans);
    return ans;
    // Write your code here.
}
