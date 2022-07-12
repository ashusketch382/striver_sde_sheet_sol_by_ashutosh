#include<bits/stdc++.h>
bool isCycle(int node, vector<int>adj[], vector<bool> &visited){
    visited[node] = true;
    queue<pair<int,int>>q;
    q.push({node, -1});
    while(!q.empty()){
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();
        for(int it: adj[node]){
            if(!visited[it]){
                visited[it] = true;
                q.push({it, node});
            }
            else if(parent != it)return true;
        }
    }
    return false;
}
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    vector<int>adj[n + 1];
    for(int i = 0; i < m ; i++){
        int a = edges[i][0];
        int b = edges[i][1];
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<bool>visited(n + 1, false);
    string ans = "No";
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            if(isCycle(i, adj, visited)){
                ans = "Yes";
                break;
            }
        }
    }
    return ans;
    // Write your code here.
}
