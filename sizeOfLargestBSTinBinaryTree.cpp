/************************************************************

    Following is the Binary Tree node structure
    
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


T.C. = O(N)
S.C. = O(H)// aux stack space
************************************************************/
class Node{
    public:
        int minVal;
        int maxVal;
        int size;
        Node(int minVal, int maxVal, int treeSize){
            this->minVal = minVal;
            this->maxVal = maxVal;
            this->size = treeSize;
        }
};

Node largestBSTSize(TreeNode<int>* root){
    if(root == NULL)return Node(INT_MAX, INT_MIN, 0);
    
    
    Node left = largestBSTSize(root->left);
    Node right = largestBSTSize(root->right);
    
    if(root->data > left.maxVal && root->data < right.minVal)return Node(min(root->data, left.minVal), max(root->data, right.maxVal), left.size + right.size + 1);
    return Node(INT_MIN, INT_MAX, max(left.size, right.size));
}

int largestBST(TreeNode<int>* root) 
{
    return largestBSTSize(root).size;
    // Write your code here.
}
