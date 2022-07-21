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
************************************************************/
/*
Time Complexity
O(N), where ‘N’ is the number of nodes in the binary search tree.
 


We are traversing each node one time while performing inorder traversal that will take O(N) time complexity.

All the calls of the next() function will overall have O(N) complexity.

Each call of the hasNext() function will work in O(1) complexity.

Thus, the final time complexity is O(N).

Space Complexity
O(N), where ‘N’ is the number of nodes in the binary search tree.



We are using a stack that can store ‘N’ nodes in the worst case. Thus, the final space complexity is O(N).


*/

#include<bits/stdc++.h>
class BSTiterator
{
    private:
        stack<TreeNode<int> *>st;
    public:
        BSTiterator(TreeNode<int> *root)
        {
            pushAll(root);
            // write your code here
        }

        int next()
        {
            TreeNode<int> *temp = st.top();
            st.pop();
            pushAll(temp->right);
            return temp->data;
            // write your code here
        }

        bool hasNext()
        {
            return !st.empty();
            // write your code here
        }
    private:
        void pushAll(TreeNode<int> *node){
            while(node != NULL){
                st.push(node);
                node = node->left;
            }
        }
};


/*
    Your BSTIterator object will be instantiated and called as such:
    BSTIterator iterator(root);
    while(iterator.hasNext())
    {
       print(iterator.next());
    }
*/