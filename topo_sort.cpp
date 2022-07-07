// Time Complexity
// O(V + E),  where  ‘V’ is the number of vertices and ‘E’ is the number of edges.

 

// The time required in calculating indegree and of while loop both will be of the order V + E

// Space Complexity
// O(V), where  ‘V’ is the number of vertices.

 

// The size of the queue and ‘result’ vector both will be of the order of ‘V’.


#include<bits/stdc++.h>
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    vector<int>res;
    vector<int>adj[v];
    for(int i = 0  ; i < e; i++){
        int a = edges[i][0];
        int b = edges[i][1];
        adj[a].push_back(b);
    }
    vector<int> indegree(v, 0);
    for(int i = 0 ; i < v; i++){
        for(int it:adj[i])indegree[it]++;
    }
    queue<int>q;
    for(int i = 0 ; i < v; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        res.push_back(curr);
        for(int it:adj[curr]){
            indegree[it]--;
            if(indegree[it] == 0)q.push(it);
        }
    }
    return res;
    // Write your code here
}