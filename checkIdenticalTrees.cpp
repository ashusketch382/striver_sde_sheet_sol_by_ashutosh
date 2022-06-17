/*                     DFS
    Time complexity: O( max(M, N) ) 
    Space complexity: O( max(M, N) )
    
    M and N are number of nodes in binary tree 1 and binary tree 2 respectively.
*/

/**********************************************************

    Following is the Binary Tree Node class structure:

    template <typename T>

    class BinaryTreeNode {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
		
        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

***********************************************************/

bool identicalTrees(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2){
    if(root1 == NULL || root2 == NULL)return root1 == root2;
    if(root1->data != root2->data)return false;
    return identicalTrees(root1->left , root2->left) && identicalTrees(root1->right, root2->right);
    // Write your code here. 	 
}






/*                        BFS
    Time complexity: O( max(M, N) ) 
    Space complexity: O( max(M, N) )
    
    M and N are number of nodes in binary tree 1 and binary tree 2 respectively.
*/

#include<queue>

vector<int> createLevelOrder(BinaryTreeNode<int>*root) {
    
    // Res will store level order traversal of the tree. 
    vector<int> res;
    
    if(root == NULL) {
        res.push_back(-1);
        return res;
    }
    
    // Using queue to implement level order traversal. 
    queue<BinaryTreeNode<int>*> q;
    
    q.push(root);
    res.push_back(root->data);
    
    while(!q.empty()) {
        
        BinaryTreeNode<int>* first = q.front();
        
        // Push the left child into queue   
        if(first->left != NULL) {
            q.push(first->left);
            res.push_back(first->left->data);
        }
        else {
            // Push -1 for NULL node. 
            res.push_back(-1);
        }
        
        // Push the right child into queue  
        if(first->right != NULL) {
            q.push(first->right);
            res.push_back(first->right->data);
        }
        else {
            // Push -1 for NULL node. 
            res.push_back(-1);
        }
        
        // Pop out the explored Node.   
        q.pop(); 

    }
    
    return res;

}


bool identicalTrees(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2) {
    
    // Store level order of tree 1 in arr1.      
    vector<int> arr1 = createLevelOrder(root1);
    
    // Store level order of tree 2 in arr2. 
    vector<int> arr2 = createLevelOrder(root2);
    
    if(arr1.size() != arr2.size()) {
        return false;
    }
    
    // Check if level order is same or not. 
    for(int i = 0; i < arr1.size(); i++) {
        if(arr1[i] != arr2[i]) {
            return false;
        }
    }
    
    return true;
    
}

