/*Time Complexity
O(N * M), where ‘N’ is the number of vertices in a graph and ‘M’ is the number of edges in the graph.

We are doing ‘N’ iterations and in each iteration, we are iterating on the edges of the graph. Thus, the final time complexity will be O(N * M).

Space Complexity
O(N), where ‘N’ is the number of vertices in a graph.

 

 We are making an array ‘dist’ which will take O(N) extra space.
*/

int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    int inf = 1000000000;
    vector<int>dist(n+1, inf);
    dist[src] = 0;
    for(int i = 1; i <= (n - 1) ; i++){
        for(int j = 0 ; j < m ; j++){
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];
            if(dist[u] != inf && dist[u] + wt < dist[v])
                dist[v] = dist[u] + wt;
        }
    }
    return dist[dest];
    // Write your code here.
}