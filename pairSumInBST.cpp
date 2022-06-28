/**********************************************************

    Following is the Binary Tree Node structure:

    template <typename T>
    class BinaryTreeNode {
        public: 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };
***********************************************************/
// T.C. = O(n)
// S.C. = O(n)

void inorder(BinaryTreeNode<int> *root, vector<int>& treeEle){
    if(root == NULL)return;
    inorder(root->left, treeEle);
    treeEle.push_back(root->data);
    inorder(root->right, treeEle);
}
bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    vector<int>treeEle;
    inorder(root, treeEle);
    int size = treeEle.size();
    int s = 0 ;
    int e = size - 1;
    while(s < e){
        if(treeEle[s] + treeEle[e] == k)return 1;
        else if(treeEle[s] + treeEle[e] < k)s++;
        else e--;
    }
    return 0;
    // Write your code here
}


/*
    Time Complexity: O(N)
    Space Complexity: O(N)
    
    Where 'N' denotes the number of nodes in the given BST
*/

#include<stack>

bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    
    /*
        Stack 'start' and 'end' to store the smaller and larger 
        values of BST respectively.
    */
    stack<BinaryTreeNode<int>*> start, end;

    BinaryTreeNode<int> *currNode = root;
    
    // Storing left values of BST in 'start'.
    while (currNode != NULL)
    {
        start.push(currNode);
        currNode = currNode -> left;
    }

    // Setting currNode again pointing to root.
    currNode = root;
    
    // Storing right values of BST in 'end'.
    while (currNode != NULL)
    {
        end.push(currNode);
        currNode = currNode -> right;
    }

    while (start.top() != end.top())
    {
        
        // Storing top node's value of 'start' stack in 'val1'.
        int val1 = start.top() -> data;
        
        // Storing top node's value of 'end' stack in 'val2'.
        int val2 = end.top() -> data;

        // If sum of 'val1' and 'val2' is equal to 'k' then return "true".
        if (val1 + val2 == k)
        {
            return true;
        }

        // Move to the next greatest closer value.
        if (val1 + val2 < k)
        {
            currNode = start.top() -> right;
            start.pop();
            
            while (currNode != NULL)
            {
                start.push(currNode);
                currNode = currNode -> left;
            }
        }

        // Move to the next smallest closer value.
        else
        {
            currNode = end.top() -> left;
            end.pop();

            while (currNode != NULL)
            {
                end.push(currNode);
                currNode = currNode -> right;
            }
        }
    }

    // If no two nodes is found, return false.
    return false;
}