/*************************************************************
 
    Following is the Binary Tree node structure.

    class BinaryTreeNode 
    {
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

*************************************************************/

vector<int> bottomView(BinaryTreeNode<int> * root){

    vector<int>res;
    queue<pair<int,BinaryTreeNode<int> *>>q;
    map<int,int>mp;
    q.push({0,root});
    while(!q.empty()){
        int level = q.front().first;
        BinaryTreeNode<int> *root = q.front().second;
        q.pop();
        mp[level] = root->data;
        if(root->left)q.push({level - 1, root->left});
        if(root->right)q.push({level + 1, root->right});
        
    }
    for(auto it:mp)res.push_back(it.second);
    return res;
    // Write your code here.
    
}
