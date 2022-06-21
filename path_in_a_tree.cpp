/*   
    template <typename T = int>
	class TreeNode
	{
		public:
		T data;
		TreeNode<T> *left;
		TreeNode<T> *right;

		TreeNode(T data)
		{
			this->data = data;
			left = NULL;
			right = NULL;
		}

		~TreeNode()
		{
			if (left != NULL)
			{
		  		delete left;
			}
			if (right != NULL)
			{
			 	delete right;
			}
		}
	};
*/

bool path(TreeNode<int> *root, int x, vector<int> &res){
    if(root == NULL)return 0;
    res.push_back(root->data);
    if(root->data == x){
        return true;
    }
    if(path(root->left, x, res))return true;
    if(path(root->right, x, res))return true;
    res.pop_back();
    return false;
}
vector<int> pathInATree(TreeNode<int> *root, int x)
{
    vector<int>res;
    path(root, x, res);
    return res;
    // Write your code here.
}
