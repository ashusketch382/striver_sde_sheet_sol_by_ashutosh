// Time Complexity
// O(N*logN)
// Space Complexity
// O(N)
// this approach is using map, which takes log(N) time to insert every element
//and we are inserting every element into it 
#include<bits/stdc++.h>
/************************************************************

Following is the Binary Tree node class
    
template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
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

************************************************************/

vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    vector<int>res;
    if(root == NULL)return res;
    map<int,vector<int>>mp;
    queue<pair<int, TreeNode<int> *>>q;
    q.push({0, root});
    while(!q.empty()){
        int level = q.front().first;
        TreeNode<int> *root = q.front().second;
        q.pop();
        if(mp.find(level) != mp.end())mp[level].push_back(root->data);
        else{
            vector<int>temp;
            temp.push_back(root->data);
            mp[level] = temp;
        }
        if(root->left)q.push({level - 1, root->left});
        if(root->right)q.push({level + 1, root->right});
    }
    for(auto v:mp){
        for(int ele: v.second)res.push_back(ele);
    }
    return res;
    //    Write your code here.
}




/*
    Time Complexity : O(N)
    Space Complexity : O(N)
    Where 'N' is the number of nodes in the given binary tree.
    this approach without map
    basically we are using vector of vector in place of map
    and for it's size we are doing post order traversal
*/

#include <queue>

void getBreadth(TreeNode<int> *root, int hrDistance, int &minLeft, int &maxRight)
{
    if (root == NULL)
    {
        return;
    }

    // Recur for the left subtree.
    getBreadth(root->left, hrDistance - 1, minLeft, maxRight);

    // Recur for the right subtree.
    getBreadth(root->right, hrDistance + 1, minLeft, maxRight);

    // Update the 'minLeft' and 'maxRight' with the horizontal distance of the current node.
    minLeft = min(minLeft, hrDistance);
    maxRight = max(maxRight, hrDistance);
}

vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    // Store the final result.
    vector<int> result;

    // Base case
    if (root == NULL)
    {
        return result;
    }

    //  To store the minimum and maximum horizontal distance.
    int minLeft = 0, maxRight = 0;

    //  Get the minimum and maximum horizontal distance.
    getBreadth(root, 0, minLeft, maxRight);

    // Create a map and store vertical order in map.
    vector<vector<int>> store(maxRight - minLeft + 1, vector<int>());

    // Initial horizontal distance.
    int hd = 0;
    int offset = abs(minLeft);

    // Every pair of queue contains node and horizontal distance with respect to the root node.
    queue<pair<TreeNode<int> *, int>> level;

    level.push(make_pair(root, hd));

    while (level.empty() == false)
    {
        // Pop element from the queue.
        pair<TreeNode<int> *, int> temp = level.front();
        level.pop();

        hd = temp.second;

        TreeNode<int> *node = temp.first;

        // Insert the value of current node in the vector of map.
        store[hd + offset].push_back(node->data);

        // For the left subtree, we pass the HD as the Horizontal distance of root minus 1.
        if (node->left != NULL)
        {
            level.push(make_pair(node->left, hd - 1));
        }

        // For the right subtree, we pass the HD as Horizontal Distance of root plus 1.
        if (node->right != NULL)
        {
            level.push(make_pair(node->right, hd + 1));
        }
    }

    for (int i = 0; i < store.size(); i++)
    {
        for (int j = 0; j < store[i].size(); ++j)
        {
            result.push_back(store[i][j]);
        }
    }

    // Return the vertical order traversal of the given binary tree.
    return result;
}