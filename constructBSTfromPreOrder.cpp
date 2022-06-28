/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class TreeNode{
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        ~TreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };

*************************************************************/
// T.C. = O(N^2)
// S.C. = O(N^2)

TreeNode<int>* BSTfromPreOrder(vector<int> &preOrder, int l, int h){
    if(l > h)return NULL;
    TreeNode<int>* root = new TreeNode<int>(preOrder[l]);
    if(l == h){
        return root;
    }
    int ind;
    int s = l + 1, e = h;
//     while(s <= e){
//         int mid = (s + e) / 2;
//         if(preOrder[mid] < preOrder[l]){
//             ind = mid;
//             s = mid + 1;
//         }
//         else{
//             e = mid - 1;
//         }
//     }
    for(ind = s; ind <= e; ind++){
        if(preOrder[l] < preOrder[ind])break;
    }
    
    root->left = BSTfromPreOrder(preOrder, l + 1 ,ind - 1);
    root->right = BSTfromPreOrder(preOrder, ind , e);
    return root;
}
TreeNode<int>* preOrderTree(vector<int> &preOrder){
    // Write your code here.
    int n = preOrder.size();
    return BSTfromPreOrder(preOrder, 0, n - 1);
}

// Another approach
/*
    Time Complexity: O(N)
    Space Complexity: O(N)

    Where N is the number of nodes in the tree.
*/

#include<climits>

TreeNode<int>* util(vector<int> &preOrder, int &preIndex, int startRange, int endRange){

    // If the preIndex is greater than the length of the array return NULL.
    if (preIndex >= preOrder.size()){
        return NULL;
    }

    int currNode = preOrder[preIndex];

    // If the current node lies inside the range then process the node.
    if (currNode > startRange && currNode < endRange){
        TreeNode<int>* root = new TreeNode<int>(currNode);

        // Increase the index by 1.
        preIndex += 1;

        // If left node exists process left.
        if (preIndex < preOrder.size()){
            root -> left = util(preOrder, preIndex, startRange, currNode);
        }
        // If right node exists process right.
        if (preIndex < preOrder.size()){
            root -> right = util(preOrder, preIndex, currNode , endRange);
        }

        // Return the root.
        return root;
    }

    // If node was not processed return NULL.
    return NULL;
}

TreeNode<int>* preOrderTree(vector<int> &preOrder){
    
    int preIndex = 0;

    // Return the util function.
    return util(preOrder, preIndex, INT_MIN, INT_MAX);
}