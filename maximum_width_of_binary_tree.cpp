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

int getMaxWidth(TreeNode<int> *root)
{
    if(root == NULL)return 0;
    int width = 0;
    queue<TreeNode<int> *>q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        width = max(width, size);
        while(size--){
            root = q.front();
            q.pop();
            if(root->left)q.push(root->left);
            if(root->right)q.push(root->right);
            
        }
    }
    return width;
    // Write your code here.
}