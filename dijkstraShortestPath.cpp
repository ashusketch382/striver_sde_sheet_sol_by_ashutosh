vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    vector<pair<int,int>>adj[vertices];
    for(int i = 0 ; i < edges ; i++){
        int a = vec[i][0];
        int b = vec[i][1];
        int wt = vec[i][2];
        adj[a].push_back({b, wt});
        adj[b].push_back({a, wt});
    }
    
    vector<int>dist(vertices, 2147483647);
    dist[source] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>q;
    q.push({0,source});
    while(!q.empty()){
        int node_dist = q.top().first;
        int node = q.top().second;
        q.pop();
        for(auto it:adj[node]){
            int new_dist = it.second;
            int new_node = it.first;
            if(dist[node] + new_dist < dist[new_node]){
                dist[new_node] = dist[node] + new_dist;
                q.push({dist[new_node],new_node});
            }
        }
    }
    return dist;
    // Write your code here.
}
