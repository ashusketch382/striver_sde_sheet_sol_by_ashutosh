/*
Time Complexity
O(V + E) per test case, where  V is the number of vertices and E is the number of edges in the graph.

 

In the worst case, Tarjan’s Algorithm performs a single DFS to obtain all the SCCs.

Space Complexity
O(V) per test case.

 */

#include<bits/stdc++.h>
void revDfs(int node, vector<int>transpose[], vector<bool>&visited, vector<int>&temp){
    visited[node] = true;
    temp.push_back(node);
    for(int it: transpose[node]){
        if(!visited[it]){
            revDfs(it, transpose, visited, temp);
        }
    }
}
void topoSort(int node, vector<int>adj[], vector<bool>&visited, stack<int>&st){
    visited[node] = true;
    for(int it:adj[node]){
        if(!visited[it])topoSort(it, adj, visited, st);
    }
    st.push(node);
}
vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
    vector<int>adj[n];
    int m = edges.size();
    for(int i = 0 ; i < m ; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }
    vector<bool>visited(n, false);
    stack<int>st;
    for(int i = 0; i < n; i++){
        if(!visited[i])topoSort(i, adj, visited, st);
    }
    vector<int>transpose[n];
    for(int i= 0; i <n; i++){
        visited[i] = false;
        for(auto it:adj[i]){
            transpose[it].push_back(i);
        }
    }
    vector<vector<int>>res;
    
    while(!st.empty()){
        int node = st.top();
        st.pop();
        vector<int>temp;
        if(!visited[node]){
            revDfs(node, transpose, visited, temp);
            res.push_back(temp);
        }
    }
    return res;
    // Write your code here.
}