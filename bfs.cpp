#include<bits/stdc++.h>
void bfs(int node, vector<int>adj[], vector<bool>& visited, vector<int> &res){
    queue<int>q;
    q.push(node);
    visited[node] = true;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        
        res.push_back(node);
        for(int v: adj[node]){
            if(!visited[v]){
                visited[v] = true;
                q.push(v);
            }
        }
    }
}
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    vector<int>adj[vertex];
    int m = edges.size();
    for(int i = 0 ; i < m ; i ++){
        int a = edges[i].first;
        int b = edges[i].second;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 0 ; i < vertex; i++){
        sort(adj[i].begin(), adj[i].end());
    }
    vector<int>res;
    vector<bool>visited(vertex + 1,false);
    for(int i = 0 ; i < vertex; i++){
        if(!visited[i])bfs(i, adj, visited, res);
    }
    return res;
    // Write your code here
}