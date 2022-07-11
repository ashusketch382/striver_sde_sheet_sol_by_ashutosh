int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
    int m = edges.size();
    vector<int>adj[n + 1];
    for(int i = 0 ; i < m ; i++){
        int a = edges[i].first;
        int b = edges[i].second;
        adj[a].push_back(b);
    }
    vector<int>inDegree(n + 1, 0);
    for(int i = 1 ; i <= n ; i++){
        for(auto it: adj[i])inDegree[it]++;
    }
    queue<int>q;
    for(int i = 1; i <= n ;i ++){
        if(inDegree[i] == 0)q.push(i);
    }
    int count = 0;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        count++;
        for(int it: adj[node]){
            inDegree[it]--;
            if(inDegree[it] == 0)q.push(it);
        }
    }
    if(count == n)return 1;
    return 0;
  // Write your code here.
}