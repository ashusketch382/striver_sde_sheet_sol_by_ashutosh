/*

Using Stack
A simple approach to solve this problem is by using a stack.
The idea is to implement the pre-order traversal of the tree using a stack.
    Time Complexity - O(N)
    Space Complexity - O(N)

    Where N is the number of nodes in the Binary Tree.
*/

#include <stack>

TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    stack<TreeNode<int> *> stk;

    TreeNode<int> *head = root;

    while (root != NULL || !stk.empty())
    {
        if (root->right != NULL)
        {
            stk.push(root->right);
        }

        if (root->left != NULL)
        {
            // Make the left child as the new right child of the node.
            root->right = root->left;
            root->left = NULL;
        }
        else if (!stk.empty())
        {
            // Pop the top node from the stack.
            // Make it the right child of the current node.
            root->right = stk.top();
            stk.pop();
        }

        // Set the right child of the node as the current node.
        root = root->right;
    }

    return head;
}


/*
    Time Complexity - O(N)
    Space Complexity - O(N)

    Where N is the number of nodes in the Binary Tree.
*/

TreeNode<int> *flattenBinaryTreeHelper(TreeNode<int> *currentNode, TreeNode<int> *lastNode)
{
    if (currentNode == NULL)
    {
        // Base Condition.
        return lastNode;
    }

    if (lastNode != NULL)
    {
        // Set currentNode as the right child of the lastNode.
        lastNode->right = currentNode;
    }

    // Store the left and right child of the currentNode in temporary variables.
    TreeNode<int> *left = currentNode->left;
    TreeNode<int> *right = currentNode->right;

    // Set the left and right pointers of currentNode to NULL.
    currentNode->left = currentNode->right = NULL;

    TreeNode<int> *newLastNode = flattenBinaryTreeHelper(left, currentNode);

    newLastNode = flattenBinaryTreeHelper(right, newLastNode);

    return newLastNode;
}

TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    TreeNode<int> *head = root;

    flattenBinaryTreeHelper(root, NULL);

    return head;
}



/*
    Time Complexity - O(N)
    Space Complexity - O(1)

    Where N is the number of nodes in the Binary Tree.
*/

TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    TreeNode<int> *currentNode = root;

    while (currentNode != NULL)
    {
        if (currentNode->left != NULL)
        {
            // Place the right subtree at its correct position (according to the linked list).
            // To do this, find the rightmost node present in the left subtree.
            TreeNode<int> *predecessor = currentNode->left;

            while (predecessor->right != NULL)
            {
                predecessor = predecessor->right;
            }

            // Make the right subtree of the current node as right child of "predecessor".
            predecessor->right = currentNode->right;

            // Make the left subtree of the current node as the new right subtree.
            currentNode->right = currentNode->left;

            currentNode->left = NULL;
        }

        // Set the right child of the node as the current node.
        currentNode = currentNode->right;
    }

    return root;
}







//my approach
/************************************************************

    Following is the TreeNode class structure.

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
// TreeNode<int> *pre = NULL;
void preOrder(TreeNode<int> *root, TreeNode<int> **pre){
    if(root == NULL)return;
    preOrder(root->right, pre);
    preOrder(root->left ,pre);
    root->right = *pre;
    root->left = NULL;
    *pre = root;
}
TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    if(root == NULL)return NULL;
    TreeNode<int> *pre = NULL;
    preOrder(root, &pre);
    return root;
    // Write your code here.
}