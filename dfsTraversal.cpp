/*
Time Complexity
O(VLogV + E), Where V is the number of vertices and E is the number of edges in the graph.

 

The time complexity of a DFS is O(V+E) and we are sorting every component which would be VlogV so overall complexity is O(V+E+VlogV) which is O(VlogV+E).

Space Complexity
O(V+E), Where V is the number of vertices and E is the number of edges in the graph.

 

To store the graph in the adjacency list.

*/
void dfs(int node, vector<int> adj[], vector<bool>& visited, vector<int>& temp){
    visited[node] = true;
    temp.push_back(node);
    for(auto it: adj[node]){
        if(!visited[it])dfs(it, adj, visited, temp);
    }
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    vector<vector<int>>res;
    vector<int>adj[V];
    for(int i = 0 ; i < E; i ++){
        int a = edges[i][0];
        int b = edges[i][1];
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 0; i  <V; i ++){
        sort(adj[i].begin(), adj[i].end());
    }
    vector<bool>visited(V, false);
    for(int i = 0; i < V; i ++){
        vector<int>temp;
        if(!visited[i])dfs(i, adj, visited, temp);
        if(!temp.empty())res.push_back(temp);
    }
    return res;
    // Write your code here
}