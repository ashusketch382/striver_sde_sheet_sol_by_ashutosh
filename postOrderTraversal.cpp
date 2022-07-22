/*
Time Complexity
O( N ), where ‘N’ is the total number of nodes in the given binary tree.

 

Every Node will be present in the stack at one time.

Hence the time complexity is O( N ).

Space Complexity
O( N ), where ‘N’ is the total number of nodes in the given binary tree.

 

The space required is proportional to the tree’s height, which can be equal to the total number of nodes in the tree in the worst case for skewed trees.

Hence the space complexity is O( N ).

*/

/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
void inorder(TreeNode *root, vector<int> &res){
    if(root == NULL)return;
    stack<TreeNode*>st;
    while(!st.empty() || root != NULL){
        if(root != NULL){
            st.push(root);
            res.push_back(root->data);
            root = root->right; // reverse of pre-order
        }
        else{
            root = st.top();
            st.pop();
            root = root->left; // reverse of pre-order
        }
    }
}
vector<int> getPostOrderTraversal(TreeNode *root)
{
    vector<int>res;
    inorder(root, res);
    reverse(res.begin(), res.end());
    return res;
    // Write your code here.
}