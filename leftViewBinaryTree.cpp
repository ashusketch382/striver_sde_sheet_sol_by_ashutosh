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
#include<bits/stdc++.h>
vector<int> getLeftView(TreeNode<int> *root)
{
    vector<int>res;
    if(root == NULL)return res;
    map<int,int>mp;
    queue<pair<int,TreeNode<int> *>>q;
    q.push({1,root});
    while(!q.empty()){
        int level = q.front().first;
        root = q.front().second;
        q.pop();
        if(mp.find(level) == mp.end())mp[level] = root->data;
        if(root->left)q.push({level + 1, root->left});
        if(root->right)q.push({level + 1, root->right});
    }
    for(auto it: mp){
        res.push_back(it.second);
    }
    return res;
    //    Write your code here
}